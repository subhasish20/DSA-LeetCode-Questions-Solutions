class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();

    // Iterate from the last digit to the first
    for (int i = n - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;
            return digits; // No carry-over needed, return early
        }
        // If the digit is 9, it becomes 0 and carry continues
        digits[i] = 0;
    }

    // If we reach here, all digits were 9 (e.g., [9, 9] ->)
    // We need to add a 1 at the beginning
    digits.insert(digits.begin(), 1);
    return digits;
}
};
