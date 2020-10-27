#include "../include/sum_interface.h"
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>

static long long sum_of_odd(const int *array, size_t size) {
    if (!array)
        return 0;
    long long odd_sum = 0;
    for (size_t i = 0; i < size; i++)
        if (array[i] % 2 != 0)
            odd_sum += array[i];
    return odd_sum;
}

static long long sum_of_even(const int *array, size_t size) {
    if (!array)
        return 0;
    long long even_sum = 0;
    for (size_t i = 0; i < size; i++)
        if (array[i] % 2 == 0)
            even_sum += array[i];
    return even_sum;
}

static pid_t create_forks(const size_t size, size_t number_of_forks, size_t* begin, size_t* end) {
    const size_t step = size / number_of_forks;
    *begin = 0;
    *end = step;
    pid_t pid = 0;
    for (int i = 0; i < number_of_forks; ++i) {
        pid = fork();
        if (pid == 0)
            return pid;
        *begin = *end;
        if (i != number_of_forks - 2)
            *end = *begin + step;
        else
            *end = size;
    }
    return pid;
}

int find_sum_dynamic(const int* array, size_t size, long long* even_sum, long long* odd_sum) {
    if (!array || !even_sum || !odd_sum)
        return 0;
    long long* shared_odd = mmap(NULL, sizeof(long long), PROT_READ | PROT_WRITE,
                                 MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    long long* shared_even = mmap(NULL, sizeof(long long), PROT_READ | PROT_WRITE,
                                 MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (!shared_odd || !shared_even) {
        return ERROR_ALLOC;
    }

    size_t begin, end;
    size_t number_of_forks = sysconf(_SC_NPROCESSORS_ONLN);
    pid_t pid = create_forks(size, number_of_forks, &begin, &end);

    if (pid == -1) {
        if (munmap(shared_odd, sizeof(long long))) {
            return ERROR_UNMAP;
        }
        return ERROR_FORK;
    }

    if (pid == 0) {
        *shared_even += sum_of_even(array + begin, end - begin);
        *shared_odd += sum_of_odd(array + begin, end - begin);
        exit(EXIT_SUCCESS);
    } else {
        for (int i = 0, status; i < number_of_forks; i++)
            waitpid(-1, &status, 0);
    }

    *odd_sum = *shared_odd;
    *even_sum = *shared_even;

    if (munmap(shared_odd, sizeof(long long)) || munmap(shared_even, sizeof(long long))) {
        return ERROR_UNMAP;
    }

    return SUCCESS;
}
