#ifndef BORDEL_H
#define BORDEL_H

#include <profan/type.h>
#include <profan.h>

#define _calloc(nmemb, lsize) calloc_func(nmemb, lsize, 0)
#define _malloc(size) malloc_func(size, 0)
#define _realloc(mem, new_size) realloc_func(mem, new_size, 0)

// uintptr_t
#define uintptr_t unsigned long

#define open(path, flags, ...) profan_open((char *) path, flags, ##__VA_ARGS__)

// bordel.c
int GetTickCount(void);

#endif
