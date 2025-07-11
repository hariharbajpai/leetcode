// User function Template for C++

/*struct Node {
    int data;
    Node *left, *right;
};*/

class Solution {
    void inorder(Node* root, vector<int>& ans) {
        if (!root) return;   
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }

    void postorder(Node* root, vector<int>& ans, int &index) {
        if (!root) return;
        postorder(root->left, ans, index);
        postorder(root->right, ans, index);
        root->data = ans[index++];
    }

public:
    void convertToMaxHeapUtil(Node* root) {
        vector<int> ans;
        inorder(root, ans);
        int index = 0;
        postorder(root, ans, index);
    }
};
