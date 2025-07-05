/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
public:
    // Function to return the top view of the binary tree
    vector<int> topView(Node *root) {
        vector<int> ans;
        if (!root) return ans;

        // Map to store hd -> first node's value
        map<int, int> hdToNode;

        // Queue for BFS: storing pair of Node and its horizontal distance
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            Node* node = p.first;
            int hd = p.second;

            // If this hd is not seen before, add it to map
            if (hdToNode.find(hd) == hdToNode.end()) {
                hdToNode[hd] = node->data;
            }

            // Push children into queue with updated hd
            if (node->left) {
                q.push({node->left, hd - 1});
            }
            if (node->right) {
                q.push({node->right, hd + 1});
            }
        }

        // Traverse the map in order of hd (left to right)
        for (auto it : hdToNode) {
            ans.push_back(it.second);
        }

        return ans;
    }
};