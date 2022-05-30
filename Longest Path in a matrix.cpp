https://practice.geeksforgeeks.org/problems/longest-path-in-a-matrix3019/1#

bool check(int i, int j, int n, int m) {
        return i >= 0 && i < n && j>=0 && j < m;
    }
    int path(int i, int j, int n, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
        if(!check(i, j, n, m))
           return 0;
        if(dp[i][j] != -1)
           return dp[i][j];
        int l = 0, r = 0, d = 0, u = 0;
        if(check(i, j - 1, n, m) && matrix[i][j] > matrix[i][j - 1])
          l = path(i, j - 1, n, m, matrix, dp);
        if(check(i, j + 1, n, m) && matrix[i][j] > matrix[i][j + 1])
          r = path(i, j + 1, n, m, matrix, dp);
        if(check(i - 1,j, n, m) && matrix[i][j] > matrix[i - 1][j])
          u = path(i - 1, j, n, m, matrix, dp);
        if(check(i + 1, j, n, m) && matrix[i][j] > matrix[i + 1][j])
          d = path(i + 1, j, n, m, matrix, dp);
          
        return dp[i][j] = 1 + max(max(max(l, r), u), d);
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(dp[i][j] == -1) {
                    ans = max(ans, path(i, j, n, m, matrix, dp));
                }
            }
        }
        return ans;
    }
