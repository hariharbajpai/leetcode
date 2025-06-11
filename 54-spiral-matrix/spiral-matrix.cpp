class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        if (row == 0) return ans; 
        int col = matrix[0].size();

        int count = 0;
        int total = row * col;

        int startinrow = 0;        
        int startingcol = 0;      
        int endingrow = row - 1;   
        int endingcol = col - 1;   

        while (count < total) {
            for (int index = startingcol; index <= endingcol; index++) {
                ans.push_back(matrix[startinrow][index]);
                count++;
            }
            startinrow++;

            for (int index = startinrow; index <= endingrow; index++) {
                ans.push_back(matrix[index][endingcol]);
                count++;
            }
            endingcol--;
 
            if (startinrow <= endingrow) {
                for (int index = endingcol; index >= startingcol; index--) {
                    ans.push_back(matrix[endingrow][index]);
                    count++;
                }
                endingrow--;
            }
 
            if (startingcol <= endingcol) {
                for (int index = endingrow; index >= startinrow; index--) {
                    ans.push_back(matrix[index][startingcol]);
                    count++;
                }
                startingcol++;
            }
        }
        return ans;
    }
};
// Initialization:

// ans is a vector that will store the result of the spiral traversal.
// row and col store the number of rows and columns in the matrix.
// count keeps track of the number of elements added to ans.
// total is the total number of elements in the matrix.
// startinrow, startingcol, endingrow, and endingcol define the boundaries of the current spiral layer.
// Spiral Traversal:

// The outer while loop continues until all elements are added to ans.
// Left to Right: Traverse the top row from startingcol to endingcol, then increment startinrow to move the top boundary down.
// Top to Bottom: Traverse the right column from startinrow to endingrow, then decrement endingcol to move the right boundary left.
// Right to Left (if applicable): If there are rows left to traverse, move from endingcol to startingcol in the bottom row, then decrement endingrow to move the bottom boundary up.
// Bottom to Top (if applicable): If there are columns left to traverse, move from endingrow to startinrow in the left column, then increment startingcol to move the left boundary right.
// Example
// Let's use the following 
// 3
// ×
// 3
// 3×3 matrix as an example:

// Copy
// 1 2 3
// 4 5 6
// 7 8 9
// Step-by-Step Traversal:
// Left to Right (Top Row):

// Traverse and add 1, 2, 3 to ans.
// startinrow becomes 1.
// Top to Bottom (Right Column):

// Traverse and add 6, 9 to ans.
// endingcol becomes 1.
// Right to Left (Bottom Row):

// Traverse and add 8, 7 to ans.
// endingrow becomes 1.
// Bottom to Top (Left Column):

// Traverse and add 4 to ans.
// startingcol becomes 1.
// Left to Right (Middle Row):

// Traverse and add 5 to ans.
// The final ans vector will be [1, 2, 3, 6, 9, 8, 7, 4, 5], which is the spiral order traversal of the matrix.