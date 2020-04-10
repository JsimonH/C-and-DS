/*Search a 2D Matrix II
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

Given target = 5, return true.
Given target = 20, return false.

*/



bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    if (matrixRowSize == 0 || matrixColSize == 0) 
    {
        return false;
    }

    if (matrix[0][0] > target) 
    {
        return false;
    }

    if (matrix[matrixRowSize - 1][matrixColSize - 1] < target) 
    {
        return false;
    }

    int x = matrixRowSize - 1;
    int y = 0;
    while (x >= 0 && y < matrixColSize) 
    {
        if (matrix[x][y] == target) 
            return true;

        else if (matrix[x][y] > target) 
            x--;
         else 
            y++;
    }
    return false;
}
