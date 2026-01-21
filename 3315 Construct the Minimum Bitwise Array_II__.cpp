class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        for (int i = 0; i < n; ++i) {
            int current = nums[i];
            
            // More generally, x OR (x+1) is always odd for x >= 0.
            if (current == 2) {
                ans[i] = -1;
                continue;
            }
            
            int temp = current;
            int bit_to_flip = 0;
            
            // Count trailing 1s
            for (int j = 0; j < 31; ++j) {
                if ((current >> j) & 1) {
                    bit_to_flip = j;
                } else {
                    // We found the first 0
                    break;
                }
            }
            
            // Flip the last 1 in the trailing 1s sequence to 0
            ans[i] = current ^ (1 << bit_to_flip);
        }
        
        return ans;
    }
};