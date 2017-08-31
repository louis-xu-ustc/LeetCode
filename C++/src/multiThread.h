//
// Created by Yunpeng Xu on 8/31/17.
//

#ifndef C_MULTITHREAD_H
#define C_MULTITHREAD_H

#include <stdio.h>
#include "pthread.h"

void* print_odd(void *threadId);
void* print_even(void *threadId);

#endif //C_MULTITHREAD_H
