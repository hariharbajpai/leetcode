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
    void inorder(TreeNode* node , vector<int>& res){
        if(node == nullptr) return;

        inorder(node->left,res);
        res.push_back(node->val);
        inorder(node->right,res);
    }
public:
    vector<int> findMode(TreeNode* root) {
      vector<int>res;
        inorder(root,res);
        unordered_map<int,int>mp;

        for(int i : res){
            mp[i]++;
        }
        int maxfre = 0;
        for(auto pair:mp){
            if(pair.second > maxfre){
                maxfre = pair.second;
            }
        }
        vector<int>ans;
        for(auto pair : mp){
            if(pair.second == maxfre) {
                ans.push_back(pair.first);
            }
        }
        return ans;
    }
};