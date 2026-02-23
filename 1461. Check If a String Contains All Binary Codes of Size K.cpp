#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        
        // If total possible substrings are less than 2^k, impossible
        if (n - k + 1 < (1 << k)) return false;
        
        unordered_set<string> seen;
        
        for (int i = 0; i <= n - k; i++) {
            seen.insert(s.substr(i, k));
        }
        
        // If we found all possible binary codes
        return seen.size() == (1 << k);
    }
};