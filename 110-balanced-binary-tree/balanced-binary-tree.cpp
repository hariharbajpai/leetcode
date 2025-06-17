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
    bool isBalanced(TreeNode* root) {
        return checkBalance(root) != -1;
    }

private:
    int checkBalance(TreeNode* node) {
        if (node == nullptr) return 0;

        int l = checkBalance(node->left);
        if (l == -1) return -1;   

        int r = checkBalance(node->right);
        if (r == -1) return -1;   

        if (abs(l - r) > 1) return -1;   

        return max(l, r) + 1;   
    }
};