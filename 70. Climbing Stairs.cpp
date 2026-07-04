#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count(int i, int n, vector<int>&dp)
    {
        if(i == n)
            return 1;
        if(i > n)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        return dp[i] = count(i +1 , n, dp ) + count(i + 2, n, dp);
    }

    int climbStairs(int n) {

        vector<int>dp(n+2,-1);

        return count(0, n,dp);
    }
};
/*class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
}; */

//SPACE OPTIMIZATION OF CLIMBING STAIRS
/*
 * class Solution {
 public:
     int climbStairs(int n) {

         if (n == 0 || n == 1)
             return 1;

         int prev2 = 1;  // Ways to reach stair 0
         int prev1 = 1;  // Ways to reach stair 1

         for (int i = 2; i <= n; i++) {
             int curr = prev1 + prev2;
             prev2 = prev1;
             prev1 = curr;
         }

         return prev1;
     }
 };
 */
