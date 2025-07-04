class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col = matrix[0].size();

        for(int i = 1;i<row;i++){
            for(int j=1;j<col;j++){
                if(matrix[i-1][j-1] != matrix[i][j]) return false;
            }
        }
        return true;
    }
};