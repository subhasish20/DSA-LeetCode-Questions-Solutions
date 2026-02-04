#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;  

        int i = 0;

        // strictly increasing
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }
        if (i == 0 || i == n - 1) return false;

        // strictly decreasing
        int mid = i;
        while (i + 1 < n && nums[i] > nums[i + 1]) {
            i++;
        }
        if (i == mid || i == n - 1) return false;

        // strictly increasing again
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }

        // must reach end
        return i == n - 1;
    }
};
