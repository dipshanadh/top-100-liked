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
        vector<vector<int>> ans;
        
        if (root == nullptr) return ans;

        queue<TreeNode *> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            int s = nodes.size();

            vector<int> v;

            for (int i = 0; i < s; ++i) {
                TreeNode *node = nodes.front(); nodes.pop();

                if (node->left != nullptr) nodes.push(node->left);
                if (node->right != nullptr) nodes.push(node->right);

                v.push_back(node->val);
            }

            ans.push_back(v);
        }

        return ans;
    }
};