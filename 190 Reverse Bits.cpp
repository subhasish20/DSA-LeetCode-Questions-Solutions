#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int reverseBits(int n) {
        unsigned int x = n;
        
        x = (x >> 16) | (x << 16);
        x = ((x & 0xff00ff00) >> 8)  | ((x & 0x00ff00ff) << 8);
        x = ((x & 0xf0f0f0f0) >> 4)  | ((x & 0x0f0f0f0f) << 4);
        x = ((x & 0xcccccccc) >> 2)  | ((x & 0x33333333) << 2);
        x = ((x & 0xaaaaaaaa) >> 1)  | ((x & 0x55555555) << 1);
        
        return x;
    }
};

/*
class Solution {
public:
    int reverseBits(int n) {
        unsigned int result = 0;
        
        for (int i = 0; i < 32; i++) {
            result <<= 1;          // Make space for next bit
            result |= (n & 1);     // Add the last bit of n
            n >>= 1;               // Shift n to process next bit
        }
        
        return result;
    }
};

*/