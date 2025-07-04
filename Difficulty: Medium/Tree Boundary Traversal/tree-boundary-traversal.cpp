/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
    bool isLeaf(Node* node) {
        return !node->left && !node->right;
    }
    
    void addLeftBoundary(Node* root, vector<int>& res) {
        Node* curr = root->left;
        while (curr) {
            if (!isLeaf(curr)) {
                res.push_back(curr->data);
            }
            if (curr->left) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
    }
    
    void addRightBoundary(Node* root, vector<int>& res) {
        Node* curr = root->right;
        vector<int> temp;
        while (curr) {
            if (!isLeaf(curr)) {
                temp.push_back(curr->data);
            }
            if (curr->right) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }
        for (int i = temp.size()-1; i >= 0; --i) {
            res.push_back(temp[i]);
        }
    }
    
    void addLeaves(Node* root, vector<int>& res) {
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        if (root->left) {
            addLeaves(root->left, res);
        }
        if (root->right) {
            addLeaves(root->right, res);
        }
    }
    
  public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int> res;
        if (!root) return res;
        
        if (!isLeaf(root)) {
            res.push_back(root->data);
        }
        
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);
        
        return res;
    }
};