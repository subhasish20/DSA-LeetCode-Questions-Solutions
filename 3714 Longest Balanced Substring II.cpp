#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int max_len = 0;

        //  Substrings with only 1 distinct character
        // Any single character is "balanced" by definition (appears once).
        if (n > 0) max_len = 1; 
        // Note: Contiguous same characters also work, e.g., "aaa" length 3.
        int curr_streak = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i-1]) curr_streak++;
            else curr_streak = 1;
            max_len = max(max_len, curr_streak);
        }

        // Substrings with exactly 2 distinct characters
        // Pairs: (a,b), (b,c), (a,c)
        vector<pair<char, char>> pairs = {{'a', 'b'}, {'b', 'c'}, {'a', 'c'}};
        for (auto& p : pairs) {
            char c1 = p.first, c2 = p.second;
            unordered_map<int, int> first_occ;
            first_occ[0] = -1;
            int diff = 0;
            int last_invalid = -1;

            for (int i = 0; i < n; i++) {
                if (s[i] != c1 && s[i] != c2) {
                    // Current char is the 3rd type, reset window
                    first_occ.clear();
                    first_occ[0] = i;
                    diff = 0;
                    last_invalid = i;
                } else {
                    if (s[i] == c1) diff++;
                    else diff--;
                    
                    if (first_occ.count(diff)) {
                        // Ensure both characters have appeared at least once in this window
                        // This logic is simplified: if diff exists, and no 'c3' intervened, 
                        // we check if both were actually present.
                        max_len = max(max_len, i - first_occ[diff]);
                    } else {
                        first_occ[diff] = i;
                    }
                }
            }
        }

        //  Substrings with exactly 3 distinct characters
        // State: (count(a)-count(b), count(a)-count(c))
        map<pair<int, int>, int> first_occ_3;
        first_occ_3[{0, 0}] = -1;
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') a++;
            else if (s[i] == 'b') b++;
            else c++;

            pair<int, int> state = {a - b, a - c};
            if (first_occ_3.count(state)) {
                max_len = max(max_len, i - first_occ_3[state]);
            } else {
                first_occ_3[state] = i;
            }
        }

        return max_len;
    }
};
