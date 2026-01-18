#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int I = 1;
        int V = 5;
        int X = 10;
        int L = 50;
        int C = 100;
        int D = 500;
        int M = 1000;
        int sum = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'I') {
                sum += I;
            }
            else if (s[i] == 'V') {
                sum += V;
            }
            else if (s[i] == 'X') {
                sum += X;
            }
            else if (s[i] == 'L') {
                sum += L;
            }
            else if (s[i] == 'C') {
                sum += C;
            }
            else if (s[i] == 'D') {
                sum += D;
            }
            else if (s[i] == 'M') {
                sum += M;
            }
            /*
            this if case for : if IX then it will be not  1 + 10 = 11 but it will be 9 acording to roman number 
            */
            if (i < s.length() - 1 && getRomanValue(s[i]) < getRomanValue(s[i + 1])) {
                sum -= 2 * getRomanValue(s[i]);  // Subtract current value twice
            }
        }
        return sum;
    }

private:
    int getRomanValue(char c) {
        if (c == 'I') return 1;
        if (c == 'V') return 5;
        if (c == 'X') return 10;
        if (c == 'L') return 50;
        if (c == 'C') return 100;
        if (c == 'D') return 500;
        if (c == 'M') return 1000;
        return 0;  // Return 0 if it's an invalid character (for safety)
    }
};

int main()
{
    string s = "MCMXCIV";
    Solution sol;
    cout<<sol.romanToInt(s);
    return 0;
}