#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{   
    public:
    int majorityElement(vector<int>& nums)
    {   
        int temp, count, MaxFequency, MajorityElement;
        temp = MaxFequency = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            temp = nums[i];
            count = 0;
            for(int j = 0; j < nums.size(); j++)
            {
                if(nums[j] == temp)
                {
                    count++;
                    if(MaxFequency < count)
                    {
                        MaxFequency = count;
                        MajorityElement = temp;

                    }
                    
                }
                if(count > nums.size() / 2) // if the size of the majority element is greatar than the size of the half array 
                {
                    MajorityElement = temp;
                    break;  
                }
            }
            
        }
        return temp;
    }
};

int main()
{
    vector<int>nums;
    nums = {2,2,1,1,1,2,2};

    Solution sol;
    cout<<sol.majorityElement(nums);
    return 0;
}