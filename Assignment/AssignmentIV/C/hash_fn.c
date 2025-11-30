/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.h

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */

#include "hash_fn.h"

int myHashInt(int key, int m) {
    // TODO: replace with your own design
    const double A = 0.6180339887498948482;
    double v = key * A;
    double fractional = v - (long long)v;  // fractional Part
    return (int)(m * fractional);
}

int myHashString(const char* str, int m) {
    unsigned long hash = 0;
    // TODO: replace with your own design
    const double A = 0.6180339887498948482;
    while (*str) {
        unsigned long c = (unsigned long)(*str);
        hash ^= (hash << 5) + (hash >> 2) + c + 1315423911UL;
        str++;
    }
    double v = hash * A;
    double fractional = v - (long long)v;
    return (int)(m * fractional);
}
