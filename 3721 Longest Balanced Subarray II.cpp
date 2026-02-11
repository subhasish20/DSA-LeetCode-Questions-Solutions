#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // Arrays for Segment Tree with Lazy Propagation
    int treeMin[400005];
    int treeMax[400005];
    int lazy[400005];

    void push(int v) {
        if (lazy[v] != 0) {
            treeMin[2 * v] += lazy[v];
            treeMax[2 * v] += lazy[v];
            lazy[2 * v] += lazy[v];
            treeMin[2 * v + 1] += lazy[v];
            treeMax[2 * v + 1] += lazy[v];
            lazy[2 * v + 1] += lazy[v];
            lazy[v] = 0;
        }
    }

    void pointSet(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            treeMin[v] = val;
            treeMax[v] = val;
            lazy[v] = 0;
        } else {
            push(v);
            int tm = (tl + tr) / 2;
            if (pos <= tm) pointSet(2 * v, tl, tm, pos, val);
            else pointSet(2 * v + 1, tm + 1, tr, pos, val);
            treeMin[v] = min(treeMin[2 * v], treeMin[2 * v + 1]);
            treeMax[v] = max(treeMax[2 * v], treeMax[2 * v + 1]);
        }
    }

    void update(int v, int tl, int tr, int l, int r, int add) {
        if (l > r) return;
        if (l == tl && r == tr) {
            treeMin[v] += add;
            treeMax[v] += add;
            lazy[v] += add;
        } else {
            push(v);
            int tm = (tl + tr) / 2;
            update(2 * v, tl, tm, l, min(r, tm), add);
            update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, add);
            treeMin[v] = min(treeMin[2 * v], treeMin[2 * v + 1]);
            treeMax[v] = max(treeMax[2 * v], treeMax[2 * v + 1]);
        }
    }

    int findLeftmost(int v, int tl, int tr, int l, int r, int target) {
        if (l > r || treeMin[v] > target || treeMax[v] < target) return -1;
        if (tl == tr) return tl;
        push(v);
        int tm = (tl + tr) / 2;
        int res = findLeftmost(2 * v, tl, tm, l, min(r, tm), target);
        if (res == -1) {
            res = findLeftmost(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, target);
        }
        return res;
    }

public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        // Reset/Initialize Segment Tree
        for (int i = 0; i <= 4 * n; ++i) {
            treeMin[i] = 1e9; // High value so it doesn't match 0
            treeMax[i] = -1e9;
            lazy[i] = 0;
        }

        vector<int> lastPos(100001, -1);
        int maxLen = 0;

        for (int j = 0; j < n; ++j) {
            int val = nums[j];
            int prev = lastPos[val];
            
           pointSet(1, 0, n - 1, j, 0);

            int delta = (val % 2 == 0 ? 1 : -1);
            update(1, 0, n - 1, prev + 1, j, delta);
            
            lastPos[val] = j;

            // Query tree for leftmost index i where Diff(i) == 0
            int i = findLeftmost(1, 0, n - 1, 0, j, 0);
            if (i != -1) {
                maxLen = max(maxLen, j - i + 1);
            }
        }

        return maxLen;
    }
};