/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

void inorder(TreeNode* root, vector<int> &ans) {
    if(root == nullptr) {
        return;
    }

    ans.push_back(root->val);
    if(root->left) {
        inorder(root->left, ans);
    }
    if(root->right) {
        inorder(root->right, ans);
    }
}

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        inorder(root, ans);

        return ans;


    }
};