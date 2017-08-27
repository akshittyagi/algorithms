/**
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
*/

#include <iostream>
#include <vector>

using namespace std;

bool binarySearch(vector<int> array, int target)
{
    int startRow = 0;
    int endRow = array.size() - 1;
    int size = array.size();
    while (startRow < endRow)
    {
        int middleIndex = (endRow + startRow + 1) / 2;
        if (target == array[middleIndex])
            return true;
        if (target > array[middleIndex])
        {
            startRow = middleIndex;
            endRow = endRow;
            size /= 2;
        }
        else if (target < array[middleIndex])
        {
            startRow = startRow;
            endRow = middleIndex - 1;
            size /= 2;
        }
    }
    if (array[startRow] == target)
        return true;
    return false;
}

class Solution
{
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int startRow = 0;
        int endRow = m - 1;
        int middleIndex;
        while (startRow < endRow)
        {
            middleIndex = (endRow + startRow + 1) / 2;
            int middleElement = matrix[middleIndex][0];
            if (target == middleElement)
                return true;
            if (target > middleElement)
            {
                startRow = middleIndex;
                endRow = endRow;
            }
            else if (target < middleElement)
            {
                endRow = middleIndex - 1;
                startRow = startRow;
            }
        }
        return binarySearch(matrix[startRow], target);
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix;
    matrix.push_back({1, 3, 5, 7});
    matrix.push_back({10, 11, 13, 17});
    matrix.push_back({20, 22, 24, 29});
    matrix.push_back({30, 33, 37, 39});
    matrix.push_back({40, 42, 49, 52});
    cout << sol.searchMatrix(matrix, 4);
    return 0;
}