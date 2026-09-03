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
    vector<int> rightSideView(TreeNode* root) {
        
        map<int, int> nodes;//level, val
        queue<pair<TreeNode*, pair<int, int>>> q; //node->(level, hd)
        vector<int> ans;

        if(root == nullptr) {
            return ans;
        }

        q.push(make_pair(root, make_pair(0, 0)));

        while(!q.empty()) {
            auto temp = q.front();
            q.pop();
            TreeNode* node = temp.first;
            int level = temp.second.first;
            int hd = temp.second.second;

            nodes[level] = node->val;

            if(node->left) {
                q.push(make_pair(node->left, make_pair(level+1, hd-1)));
            }

            if(node->right) {
                q.push(make_pair(node->right, make_pair(level+1, hd+1)));
            }
        }

        for(auto i: nodes) {
            ans.push_back(i.second);
        }

        return ans;
    }
};