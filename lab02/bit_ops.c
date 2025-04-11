#include <stdio.h>
#include "bit_ops.h"

// Return the nth bit of x.
// Assume 0 <= n <= 31
unsigned get_bit(unsigned x,
                 unsigned n) {
    const unsigned mask = 1u;
    return (x >> n) & mask;
}
// Set the nth bit of the value of x to v.
// Assume 0 <= n <= 31, and v is 0 or 1
void set_bit(unsigned * x,
             unsigned n,
             unsigned v) {
    const unsigned setNthZero = ~(1u << n);
    *x &= setNthZero;
    const unsigned setNthV = v << n;
    *x |= setNthV;
}
// Flip the nth bit of the value of x.
// Assume 0 <= n <= 31
void flip_bit(unsigned * x,
              unsigned n) {
    const unsigned value = get_bit(*x, n);
    const unsigned flipMask = 1u;
    const unsigned flipValue = value ^ flipMask;
    set_bit(x, n, flipValue);
}

