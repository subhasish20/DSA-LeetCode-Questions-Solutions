#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return 0;

        const long long NEG_INF = LLONG_MIN / 4;

        /*
          incLP  : max sum of nums[l..p] where nums[l..p] is strictly increasing
          decPQ  : max sum of nums[l..q] where nums[l..p] increasing
                                           and nums[p..q] decreasing
          incQR  : max sum of nums[l..r] where nums[l..p] increasing
                                           nums[p..q] decreasing
                                           nums[q..r] increasing (trionic)
        */

        long long incLP_any = nums[0];   // nums[l..p], length ≥ 1
        long long incLP     = NEG_INF;   // nums[l..p], length ≥ 2
        long long decPQ     = NEG_INF;   // nums[l..q]
        long long incQR     = NEG_INF;   // nums[l..r]
        long long answer    = NEG_INF;

        for (int i = 1; i < n; ++i) {
            long long curr = nums[i];
            long long prev = nums[i - 1];

            long long next_incLP_any = curr;
            long long next_incLP     = NEG_INF;
            long long next_decPQ     = NEG_INF;
            long long next_incQR     = NEG_INF;

            // -------- nums[l..p] strictly increasing --------
            if (curr > prev) {
                next_incLP_any = max(incLP_any + curr, curr);
                next_incLP = incLP_any + curr;  // ensures l < p
            }

            // -------- nums[p..q] strictly decreasing --------
            if (curr < prev) {
                // start decreasing after increasing
                if (incLP != NEG_INF)
                    next_decPQ = max(next_decPQ, incLP + curr);

                // continue decreasing
                if (decPQ != NEG_INF)
                    next_decPQ = max(next_decPQ, decPQ + curr);
            }

            // -------- nums[q..r] strictly increasing --------
            if (curr > prev) {
                // start final increasing after decrease
                if (decPQ != NEG_INF)
                    next_incQR = max(next_incQR, decPQ + curr);

                // continue final increasing
                if (incQR != NEG_INF)
                    next_incQR = max(next_incQR, incQR + curr);
            }

            if (next_incQR != NEG_INF)
                answer = max(answer, next_incQR);

            incLP_any = next_incLP_any;
            incLP     = next_incLP;
            decPQ     = next_decPQ;
            incQR     = next_incQR;
        }

        return answer == NEG_INF ? 0 : answer;
    }
};
