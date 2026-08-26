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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr) {
            return result;
        }

        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        result.push_back({root->val});

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node == nullptr) {
                if(q.empty()) {
                    break;
                } else {
                    q.push(nullptr);
                    result.push_back(ans);
                    ans.clear();
                }
            } else {
                if(node->left){
                    q.push(node->left);
                    ans.push_back((node->left)->val);
                }
                if(node->right) {
                    q.push(node->right);
                    ans.push_back((node->right)->val);
                }
                
                
            }
        }

        return result;
    }
};