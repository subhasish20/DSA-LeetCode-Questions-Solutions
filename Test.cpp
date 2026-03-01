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


class Solution 
{
public:

    void traverse(TreeNode* root, vector<int>& result)
    {
        if (root == NULL)
            return;

        // If leaf node, store value
        if (root->left == NULL && root->right == NULL)
        {
            result.push_back(root->val);
            return;
        }

        traverse(root->left, result);
        traverse(root->right, result);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        vector<int> result1;
        vector<int> result2;

        traverse(root1, result1);
        traverse(root2, result2);

        return result1 == result2;
    }
};