#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int first_value = nums[0];

        vector<int>remaining(nums.begin() + 1, nums.end());

        sort(remaining.begin(),remaining.end());

        return first_value + remaining[0] + remaining[1];
    }
};