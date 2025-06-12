#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int row = mat.size();

        // Check if the original matrix matches the target
        if (mat == target) {
            return true;
        }

        // Check 90-degree rotation
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < i; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        for (int i = 0; i < row; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
        if (mat == target) {
            return true;
        }

        // Check 180-degree rotation
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < i; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        for (int i = 0; i < row; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
        if (mat == target) {
            return true;
        }

        // Check 270-degree rotation
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < i; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        for (int i = 0; i < row; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
        if (mat == target) {
            return true;
        }

        // If none of the rotations match, return false
        return false;
    }
};
