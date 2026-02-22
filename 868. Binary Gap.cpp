#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int binaryGap(int n) {
        int lastPosition = -1;   // stores position of last seen '1'
        int maxDistance = 0;     // stores maximum distance
        int position = 0;        // current bit position
        
        while (n > 0) {
            if (n & 1) {  // if current bit is 1
                if (lastPosition != -1) {
                    maxDistance = max(maxDistance, position - lastPosition);
                }
                lastPosition = position;
            }
            n >>= 1;     
            position++;
        }
        
        return maxDistance;
    }
};