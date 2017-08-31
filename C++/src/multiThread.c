//
// Created by Yunpeng Xu on 8/31/17.
//

#include <stdbool.h>
#include <stdlib.h>
#include "multiThread.h"

#define MAX_K 20
//mutex is used to protect critical section, has nothing to do with wait&signal
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
//condition variables are used by threads to obtain and deliver turn (wait&signal)
pthread_cond_t cv;
static bool printOddNum;

#if 1
void *print_even(void *threadId) {
    printf("\n Job %d started\n", *(int *) threadId);
    for (int k = 1; k <=MAX_K / 2; k++) {
        pthread_mutex_lock(&mutex);
        while (printOddNum) {
            pthread_cond_wait(&cv, &mutex);
        }
        printf("%d ", 2 * k);
        printOddNum = true;
        pthread_cond_signal(&cv);
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

void *print_odd(void *threadId) {
    printf("\n Job %d started\n", *(int *) threadId);
    for (int k = 1; k <= MAX_K / 2; k++) {
        pthread_mutex_lock(&mutex);
        while (!printOddNum) {
            pthread_cond_wait(&cv, &mutex);
        }
        printf("%d ", 2 * k - 1);
        printOddNum = false;
        pthread_cond_signal(&cv);
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}
#else

static int k = 1;

void *print_even(void *threadId) {
    printf("\n Job %d started\n", *(int *) threadId);
    while (k <= MAX_K) {
        pthread_mutex_lock(&mutex);
        if ((k & 1) == 0) {
            printf("%d ", k);
            k++;
        }
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

void *print_odd(void *threadId) {
    printf("\n Job %d started\n", *(int *) threadId);
    while (k <= MAX_K) {
        pthread_mutex_lock(&mutex);
        if ((k & 1) == 1) {
            printf("%d ", k);
            k++;
        }
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}
#endif

int check_endian() {
    int a = 0x01020304;
    char* b = (char*)&a;
    if (*b == 0x04) {
        printf("little endian!\n");
    } else {
        printf("big endian!\n");
    }
    return 0;
}

int main(int argc, char **argv) {
    pthread_t threads[2];
    printOddNum = true;

    check_endian();
    printf("test multi thread!");

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cv, NULL);
    int threadId0 = 0;
    int threadId1 = 1;
    pthread_create(&threads[0], NULL, print_odd, &threadId0);
    pthread_create(&threads[1], NULL, print_even, &threadId1);

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cv);

    return 0;
}
