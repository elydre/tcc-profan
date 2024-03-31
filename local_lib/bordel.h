#ifndef BORDEL_H
#define BORDEL_H

#include <profan.h>
#include <type.h>

#define _calloc(nmemb, lsize) calloc_func(nmemb, lsize, 0)
#define _malloc(size) malloc_func(size, 0)
#define _realloc(mem, new_size) realloc_func(mem, new_size, 0)

// uintptr_t
#define uintptr_t unsigned long

// errno variable
static int errno;

struct timeval {
    long tv_sec;
    long tv_usec;
};

struct timezone {
    int tz_minuteswest;
    int tz_dsttime;
};

// define off_t type
#define off_t long

// define size_t type
#define ssize_t long

#define open(path, flags, ...) profan_open((char *) path, flags, ##__VA_ARGS__)

// bordel.c
long double strtold(const char *theString, char **end);
int GetTickCount(void);

#endif
