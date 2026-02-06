#include<bits/stdc++.h>
using namespace std;
    
class Solution {
public:
    int pivotInteger(int n) {
        int total = n * (n + 1) / 2;
        int x = sqrt(total);
//     x² = n(n + 1) / 2
        if (x * x == total)
            return x;
        return -1;
    }
};
