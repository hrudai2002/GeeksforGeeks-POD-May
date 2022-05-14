int MaxGold(vector<vector<int>>&matrix){
   int n = matrix.size(), m = matrix[0].size();
   vector<vector<int>> dp(n, vector<int>(m, -1));
   for(int i = 0; i < m; ++i)
      dp[0][i] = matrix[0][i];
   
   for(int i = 1; i < n; ++i) {
       for(int j = 0; j < m; ++j) {
           if(matrix[i][j] != -1) {
               if(j - 1 >= 0) 
                   if(dp[i - 1][j - 1] != -1) dp[i][j] = max(dp[i][j], matrix[i][j] + dp[i - 1][j - 1]);
               if(j + 1 < m)
                   if(dp[i - 1][j + 1] != -1) dp[i][j] = max(dp[i][j], matrix[i][j] + dp[i - 1][j + 1]);
               if(dp[i - 1][j] != -1)
               dp[i][j] = max(dp[i][j], matrix[i][j] + dp[i - 1][j]);
           }
       }
   }
   int mxscore = 0;
   for(int i = n - 1; i >= 0; --i) {
       for(int j = 0; j < m; ++j)
         mxscore = max(mxscore, dp[i][j]);
   }
   return mxscore;
}
