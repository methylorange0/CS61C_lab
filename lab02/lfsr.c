#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

void lfsr_calculate(uint16_t *reg) {
    uint16_t temp = *reg;
    uint16_t r0, r2, r3, r5, r16;
    const uint16_t mask = 1;
    r0 = mask & temp;
    temp = temp >> 2;
    r2 = mask & temp;
    temp = temp >> 1;
    r3 = mask & temp;
    temp = temp >> 2;
    r5 = mask & temp;
    r16 = (((r0 ^ r2) ^ r3)) ^ r5;
    r16 = r16 << 15;
    *reg = *reg >> 1;
    *reg |= r16;
}

