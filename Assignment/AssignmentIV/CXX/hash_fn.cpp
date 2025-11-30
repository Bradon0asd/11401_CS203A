/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/26: Initial implementation
    - 2025/11/30: Refactored to use hash_fn.hpp

   Developer: Kuna-Ti Chiang <s1123306@mail.yzu.edu.tw>
 */
#include "hash_fn.hpp"

int myHashInt(int key, int m) {
    // TODO: replace with your own design
    const double A = 0.6180339887498948482; // Knuth's multiplicative constant (from CLRS, "Introduction to Algorithms", page 232)
    double value = key * A; // Multiply the key
    double fractional = value - (long long)value; // Select the fractional Part
    return static_cast<int>(m * fractional);
}

int myHashString(const std::string& str, int m) {
    unsigned long hash = 0;
    // TODO: replace with your own design
    const double A = 0.6180339887498948482;
    for (char c : str) {
        hash ^= (hash << 5) + (hash >> 2) + static_cast<unsigned long>(c) + 1315423911; //variant of PJW_hash_function 
    }
    /*
        XOR new hash content with previous hash
        The new content each SHIFT left 5 bits and right 2 bits,
        Final add the big constant value to mix bits. 
    */
    double value = hash * A;
    double fractional = value - (long long)value;
    return static_cast<int>(m * fractional);
}
