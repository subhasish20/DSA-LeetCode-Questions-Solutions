class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        auto isNonDecreasing = [&](vector<int>& arr) {
            for (int i = 1; i < arr.size(); i++) {
                if (arr[i] < arr[i - 1])
                    return false;
            }
            return true;
        };

        // Repeat until array becomes non-decreasing
        while (!isNonDecreasing(nums)) {
            int minSum = INT_MAX;
            int index = 0;

            // Find adjacent pair with minimum sum
            for (int i = 0; i < nums.size() - 1; i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum) {
                    minSum = sum;
                    index = i;   // leftmost minimum sum pair
                }
            }

            // Replace the pair with their sum
            nums[index] = nums[index] + nums[index + 1];
            nums.erase(nums.begin() + index + 1);

            operations++;
        }

        return operations;
    }
};
