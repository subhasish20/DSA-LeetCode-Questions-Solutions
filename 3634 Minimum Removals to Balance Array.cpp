#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        // Sort the array to easily identify min and max in a range
        sort(nums.begin(), nums.end());
        
        int left = 0;
        int max_kept = 0;
        
        //  Use a sliding window to find the largest balanced subarray
        for (int right = 0; right < n; ++right) {
            // While the condition is violated, shrink the window from the left
            while ((long long)nums[right] > (long long)nums[left] * k) {
                left++;
            }
            
            // Calculate the number of elements in the current valid window
            max_kept = max(max_kept, right - left + 1);
        }
        
        //  Minimum removals = Total elements - maximum elements kept
        return n - max_kept;
    }
};