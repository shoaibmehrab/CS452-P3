#include <pthread.h>
#include <stdlib.h>
#include "lab.h"

typedef struct {
    int *A;
    int p;
    int r;
} thread_data_t;

void *thread_mergesort(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    mergesort_s(data->A, data->p, data->r);
    pthread_exit(NULL);
}

void mergesort_mt(int *A, int n, int num_threads) {
    if (num_threads > MAX_THREADS) {
        num_threads = MAX_THREADS;
    }

    pthread_t threads[num_threads];
    thread_data_t thread_data[num_threads];
    int chunk_size = n / num_threads;
    int remainder = n % num_threads;

    int start = 0;
    for (int i = 0; i < num_threads; i++) {
        int end = start + chunk_size - 1;
        if (i < remainder) {
            end++;
        }
        thread_data[i].A = A;
        thread_data[i].p = start;
        thread_data[i].r = end;
        pthread_create(&threads[i], NULL, thread_mergesort, (void *)&thread_data[i]);
        start = end + 1;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    int current_size = chunk_size;
    if (remainder > 0) {
        current_size++;
    }

    while (current_size < n) {
        for (int i = 0; i < n; i += 2 * current_size) {
            int mid = i + current_size - 1;
            int end = i + 2 * current_size - 1;
            if (end >= n) {
                end = n - 1;
            }
            if (mid < end) {
                merge_s(A, i, mid, end);
            }
        }
        current_size *= 2;
    }
}