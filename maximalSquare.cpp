/**
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
s
*/
class Solution
{
  public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        if (m == 0)
            return 0;
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxSize = 0;
        for (int j = 0; j < n; j++)
        {
            dp[0][j] = matrix[0][j] - '0';
            maxSize = max(maxSize, dp[0][j]);
        }
        for (int i = 0; i < m; i++)
        {
            dp[i][0] = matrix[i][0] - '0';
            maxSize = max(maxSize, dp[i][0]);
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == '1')
                {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                    maxSize = max(maxSize, dp[i][j]);
                }
            }
        }

        return maxSize * maxSize;
    }
};