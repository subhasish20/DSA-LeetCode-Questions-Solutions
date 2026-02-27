#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> bits(10001, 0);
        
        for (int i = 1; i <= 10000; i++) {
            bits[i] = bits[i >> 1] + (i & 1);
        }
        
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            if (bits[a] == bits[b])
                return a < b;
            return bits[a] < bits[b];
        });
        
        return arr;
    }
};