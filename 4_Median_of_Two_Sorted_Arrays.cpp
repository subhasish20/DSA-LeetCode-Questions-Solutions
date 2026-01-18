#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int>c;
		float median;
		c.resize(nums1.size() + nums2.size());
		
		merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), c.begin());
		size_t n = c.size();
		if(c.size() % 2 == 0)
		{
			median  = (c[n/2 - 1] + c[n/2]) / 2.0;
			cout<<median;
		}
		else 
		{
			median = c[n / 2];
			cout<<median;
		}
		
    }
};

int main()
{
	vector<int>nums1 = {1,2,3};
	vector<int>nums2 = {4,5,6,7};
	Solution sol;
	
	sol.findMedianSortedArrays(nums1, nums2);
	return 0;
}