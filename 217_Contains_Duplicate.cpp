#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    
    bool checkDuplicate(vector<int>& nums, int check) {
        if (check == nums.size()) 
            return false;  // reached end → no duplicates
        
        int count = 0;

        // Count occurrences of nums[check]
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == nums[check]) {
                count++;
            }
        }

        if (count > 1)
            return true;   // duplicate found

        // recurse with next index
        return checkDuplicate(nums, check + 1);
    }

    bool containsDuplicate(vector<int>& nums) {
        return checkDuplicate(nums, 0);
    }
};

/*
OR 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());   // sort the array
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) { // check adjacent duplicates
                return true;
            }
        }
        return false;
    }
};

*/

int main()
{
    vector<int>nums = {1,2,3,1};
    Solution s;
    s.containsDuplicate(nums);

    return 0;
}