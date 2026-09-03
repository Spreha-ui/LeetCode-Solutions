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

void solve(TreeNode* root, long long sum, long long &totalsum) {
    if(root->left == nullptr && root->right == nullptr) {
        sum = sum*10 + root->val;
        totalsum = totalsum + sum;
        return;
    }

    sum = sum*10 + root->val;

    if(root->left) {
        solve(root->left, sum, totalsum);
    }

    if(root->right) {
        solve(root->right, sum, totalsum);
    }
}

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        long long totalsum = 0;

        solve(root, 0, totalsum);

        return totalsum;
    }
};