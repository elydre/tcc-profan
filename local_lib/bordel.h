#ifndef BORDEL_H
#define BORDEL_H

#include <profan/type.h>
#include <profan.h>

// uintptr_t
#define uintptr_t unsigned long

#define open(path, flags, ...) profan_open((char *) path, flags, ##__VA_ARGS__)

// bordel.c
int GetTickCount(void);

#endif
