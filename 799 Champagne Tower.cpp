#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {

        double tower[101][101] = {0.0};
        
        tower[0][0] = (double)poured;
        
        for (int r = 0; r <= query_row; ++r) {
            for (int c = 0; c <= r; ++c) {

                if (tower[r][c] > 1.0) {
                    double excess = (tower[r][c] - 1.0) / 2.0;
                    tower[r][c] = 1.0; // The current glass stays full
                    
                    tower[r + 1][c] += excess;
                    tower[r + 1][c + 1] += excess;
                }
            }
        }
        
        return min(1.0, tower[query_row][query_glass]);
    }
};