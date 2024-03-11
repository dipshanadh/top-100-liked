class Solution {
public:
    int max = 0;

    int diameterOfBinaryTree(TreeNode *root) {
        maxDepth(root);
        return max;
    }

    int maxDepth(TreeNode *root) {
        if (root == nullptr) return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        max = std::max(max, left + right);

        return std::max(left, right) + 1;
    }
};