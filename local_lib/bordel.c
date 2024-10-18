// __udivdi3 definition
unsigned long long __udivdi3(unsigned long long num, unsigned long long den) {
    unsigned long long quot = 0, qbit = 1;

    if (den == 0) {
        return 0; // divide by zero
    }

    // Left-justify denominator and count shift
    while ((signed long long) den >= 0) {
        den <<= 1;
        qbit <<= 1;
    }

    while (qbit) {
        if (den <= num) {
            num -= den;
            quot += qbit;
        }
        den >>= 1;
        qbit >>= 1;
    }

    return quot;
}

// __umoddi3 definition
unsigned long long __umoddi3(unsigned long long num, unsigned long long den) {
    if (den == 0) {
        return num; // divide by zero
    }

    // Left-justify denominator and count shift
    while ((signed long long) den >= 0) {
        den <<= 1;
    }

    while (den > num) {
        den >>= 1;
    }

    return num - den;
}

// __udivmoddi4 definition
unsigned long long __udivmoddi4(unsigned long long num, unsigned long long den, unsigned long long *rem_p) {
    unsigned long long quot = 0, qbit = 1;
    unsigned long long rem = 0;

    if (den == 0) {
        return 0; // divide by zero
    }

    // Left-justify denominator and count shift
    while ((signed long long) den >= 0) {
        den <<= 1;
        qbit <<= 1;
    }

    while (qbit) {
        if (den <= num) {
            num -= den;
            quot += qbit;
        }
        den >>= 1;
        qbit >>= 1;
    }

    rem = num;

    *rem_p = rem;
    return quot;
}
