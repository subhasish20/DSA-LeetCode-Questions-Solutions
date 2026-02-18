#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    // Brian Kernighan’s Algorithm
    int countBits(int n) {
        int count = 0;
        while (n) {
            n &= (n - 1);  // removes the lowest set bit
            count++;
        }
        return count;
    }
    
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        
        for (int hour = 0; hour < 12; hour++) {
            for (int minute = 0; minute < 60; minute++) {
                
                int totalBits = countBits(hour) + countBits(minute);
                
                if (totalBits == turnedOn) {
                    string time = to_string(hour) + ":";
                    
                    // ensure minute has two digits
                    if (minute < 10)
                        time += "0";
                        
                    time += to_string(minute);
                    
                    result.push_back(time);
                }
            }
        }
        
        return result;
    }
};
