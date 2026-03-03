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
    int provideAnswer(TreeNode* root, int nowMax)
    {
        if(root == NULL)
            return 0;
        int count = 0;
        if(root->val >= nowMax)
            count++;

        int newMax = max(nowMax,root->val);
        int LCount =  provideAnswer(root->left, newMax);
        int RCount = provideAnswer(root->right, newMax);
        return count + LCount + RCount;
    }
    int goodNodes(TreeNode* root) {
        if(root == nullptr)
        return 0;

        return provideAnswer(root, root->val);
    }
};