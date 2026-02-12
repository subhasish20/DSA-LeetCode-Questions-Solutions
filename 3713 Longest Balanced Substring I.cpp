#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int maxLen = 0;

        for (int i = 0; i < n; ++i) {
            // Frequency array for the 26 lowercase letters
            vector<int> freq(26, 0);
            
            for (int j = i; j < n; ++j) {
                // Increment frequency of the current character
                freq[s[j] - 'a']++;

                // Check if all present characters have the same frequency
                if (isBalanced(freq)) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }

private:
    bool isBalanced(const vector<int>& freq) {
        int targetFreq = -1;

        for (int count : freq) {
            if (count > 0) {
                if (targetFreq == -1) {
                    targetFreq = count;
                } else if (count != targetFreq) {
                    return false;
                }
            }
        }
        return true;
    }
};