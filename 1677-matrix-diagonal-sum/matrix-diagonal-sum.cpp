class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        int sum = 0;
        
        for(int i = 0; i < row; i++) {
            // Primary diagonal (top-left to bottom-right)
            sum += mat[i][i];
            
            // Secondary diagonal (top-right to bottom-left)
            // Skip the center element if the matrix has odd size
            if (i != row - 1 - i) {
                sum += mat[i][row - 1 - i];
            }
        }
        
        return sum;
    }
};