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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        

        map<int, map<int, multiset<int>>> nodes; // HD->level-> nodes
        queue<pair<TreeNode*, pair<int, int>>> q;
        vector<vector<int>> ans;

        if(root == nullptr) {
            return ans;
        }

        q.push(make_pair(root, make_pair(0,0)));

        while(!q.empty()) {
            auto temp = q.front();
            q.pop();
            TreeNode* node = temp.first;
            int hd = temp.second.first;
            int level = temp.second.second;

            nodes[hd][level].insert(node->val);

            if(node->left) {
                q.push(make_pair(node->left, make_pair(hd-1, level+1)));
            }
            if(node->right) {
                q.push(make_pair(node->right, make_pair(hd+1, level+1)));
            }
        }

        for(auto i: nodes) {

            vector<int> column;

            for(auto j: i.second) {

                for(auto k: j.second) {
                    column.push_back(k);
                }
            }
            ans.push_back(column);
        }

        return ans;

    }
};