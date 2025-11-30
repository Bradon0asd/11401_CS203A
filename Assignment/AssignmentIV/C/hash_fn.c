/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/26: Initial implementation
    - 2025/11/30: Refactored to use hash_fn.h

   Developer: Kuan-Ti Chiang <s1123306@mail.yzu.edu.tw>
 */

#include "hash_fn.h"

int myHashInt(int key, int m) {
    // TODO: replace with your own design
    const double A = 0.6180339887498948482; // Knuth's multiplicative constant (from CLRS, "Introduction to Algorithms", page 232)
    double value = key * A; // Multiply the key
    double fractional = value - (long long)value;  // Select the fractional Part
    return (int)(m * fractional);
}

int myHashString(const char* str, int m) {
    unsigned long hash = 0;
    // TODO: replace with your own design
    const double A = 0.6180339887498948482;
    while (*str) {
        unsigned long c = (unsigned long)(*str);
        hash ^= (hash << 5) + (hash >> 2) + c + 1315423911UL; //variant of PJW_hash_function 
        /*
            XOR new hash content with previous hash
            The new content each SHIFT left 5 bits and right 2 bits,
            Final add the big constant value to mix bits. 
        */
        str++;
    }
    double value = hash * A; // same as above
    double fractional = value - (long long)value;
    return (int)(m * fractional);
}
