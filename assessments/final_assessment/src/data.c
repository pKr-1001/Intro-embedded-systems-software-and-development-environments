#include "data.h"
#include <stdio.h>

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {

    // Check for NULL pointer
    if (ptr == NULL) {
        return 0;
    }

    // Check for invalid base
    if (base < 2 || base > 16) {
        return 0;
    }

    // Check for zero
    if (data == 0) {
        *ptr = '0';
        return 1;
    }

    // Check for negative number
    uint8_t isNeg = 0;
    if (data < 0) {
        isNeg = 1;
        data = -data;
    }

    uint8_t length = 0;
    while (data != 0) {
        int32_t remainder = data % base;
        if (remainder > 9) {
            *(ptr + length) = (remainder - 10) + 'A';
        } else {
            *(ptr + length) = remainder + '0';
        }
        data /= base;
        length++;
    }
    if (isNeg) {
        *(ptr + length) = '-';
        length++;
    }

    for (uint8_t i = 0; i < length / 2; i++) {
        uint8_t temp = *(ptr + i);
        *(ptr + i) = *(ptr + length - i - 1);
        *(ptr + length - i - 1) = temp;
    }
    return length;
}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {

    // Check for NULL pointer
    if (ptr == NULL) {
        return 0;
    }

    // Check for invalid base
    if (base < 2 || base > 16) {
        return 0;
    }

    // Check for zero
    int32_t result = 0;
    uint8_t isNeg = 0;
    
    if (*ptr == '-') {
        isNeg = 1;
        ptr++;
        digits--;
    }

    for (uint8_t i = 0; i < digits; i++) {
        result *= base;

        if (*ptr >= '0' && *ptr <= '9') {
            result += *ptr - '0';
        } else if (*ptr >= 'A' && *ptr <= 'F') {
            result += *ptr - 'A' + 10;
        } else {
            return 0;
        }
        ptr++;
    }

    if (isNeg) {
        result = -result;
    }
    return result;
}
