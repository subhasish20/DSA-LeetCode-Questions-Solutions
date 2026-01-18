#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
void rotate(vector<int>& nums, int k) 
{
    int n = nums.size();
    vector<int> temp(n);

    for(int i = 0; i < n; i++)
        temp[(i + k) % n] = nums[i];

    nums = temp;
}



};

int main()
{   
    vector<int>nums = {1,2,3,4,5,6,7};
    int k = 3;

    Solution sol;
    sol.rotate(nums,k);

    return 0;
}