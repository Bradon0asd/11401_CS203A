/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/30: Refactored to use hash_fn.hpp

   Developer: Kuna-Ti Chiang <s1123306@mail.yzu.edu.tw>
 */
#include "hash_fn.hpp"

int myHashInt(int key, int m) {
    // TODO: replace with your own design
    const double A = 0.6180339887498948482;
    double v = key * A;
    double fractional = v - (long long)v;
    return static_cast<int>(m * fractional);
}

int myHashString(const std::string& str, int m) {
    unsigned long hash = 0;
    // TODO: replace with your own design
    const double A = 0.6180339887498948482;
    for (char c : str) {
        hash ^= (hash << 5) + (hash >> 2) + static_cast<unsigned long>(c) + 1315423911;
    }
    double v = hash * A;
    double fractional = v - (long long)v;  // 取小數部分（不使用 floor、不使用 modf）
    return static_cast<int>(m * fractional);
}
