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
    // Helper function to do DFS traversal and collect paths
    void dfs(TreeNode* node, vector<string>& ans, string path) {
        if (!node) return;

        // Convert current node value to string and append to path
        path += to_string(node->val);

        // If it's a leaf node, add the path to answer
        if (!node->left && !node->right) {
            ans.push_back(path);
            return;
        }

        // Otherwise, continue to children
        if (node->left)  dfs(node->left, ans, path + "->");
        if (node->right) dfs(node->right, ans, path + "->");
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path = "";
        dfs(root, ans, path);
        return ans;
    }
};