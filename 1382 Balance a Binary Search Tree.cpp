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
    vector<int> nodes;

    void storeInorder(TreeNode* root) {
        if (!root) return;
        storeInorder(root->left);
        nodes.push_back(root->val);
        storeInorder(root->right);
    }

    TreeNode* buildTree(int start, int end) {
        if (start > end) return nullptr;

        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nodes[mid]);

        root->left = buildTree(start, mid - 1);
        root->right = buildTree(mid + 1, end);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        nodes.clear();
        storeInorder(root);
        return buildTree(0, nodes.size() - 1);
    }
};