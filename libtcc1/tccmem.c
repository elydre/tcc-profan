/*
 * freestanding implementation of memory functions use by
 * tcc for variable (and struct) initialization / copy.
 *
 * Note: this file is not a official part of tcc, it is
 * not present on the libtcc1.a archive, but included
 * as elf object for compilation without libc.
 */

void *memmove(void *s1, const void *s2, unsigned n) {
    register const char *p = (const char *) s2;
    register char *s = (char *) s1;

    if (p >= s) {
        while (n) {
            *s++ = *p++;
            --n;
        }
    } else {
        while (n) {
            --n;
            s[n] = p[n];
        }
    }

    return s1;
}

void *memcpy(void *s1, const void *s2, unsigned n) {
    register const char *p = (const char *) s2;
    register char *s = (char *) s1;

    while (n) {
        *s++ = *p++;
        --n;
    }

    return s1;
}

void *memset(void *s, int c, unsigned n) {
    register unsigned char *p = (char *) s;

    while (n) {
        *p++ = (unsigned char) c;
        --n;
    }

    return s;
}
