#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sumRootToLeaf(TreeNode* root, int currentSum = 0) {
        if (!root) return 0;

        // Shift left by 1 (multiply by 2) and add current node's bit
        currentSum = (currentSum << 1) | root->val;

        if (!root->left && !root->right) {
            return currentSum;
        }

        // Otherwise, continue DFS on children and return their sum
        return sumRootToLeaf(root->left, currentSum) + 
               sumRootToLeaf(root->right, currentSum);
    }
};