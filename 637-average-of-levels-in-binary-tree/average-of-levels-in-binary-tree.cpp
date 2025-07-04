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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>res;

        if(!root) return res;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            double sum =0;
            int n = q.size();

            for(int i = 0;i<n;i++){
                TreeNode* front = q.front();
                q.pop();

                sum += front->val;

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            res.push_back(sum/n);
        }
        return res;
    }
};