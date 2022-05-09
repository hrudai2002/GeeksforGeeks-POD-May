double findProb(int N,int x, int y, int steps)
	{
	    vector<vector<double>> dp(N, vector<double>(N, 0.0));
	    dp[x][y] = 1.0;
	    
	    int X[] = {1, 1, -1, -1, 2, 2, -2, -2};
	    int Y[] = {2, -2, 2, -2, 1, -1, 1, -1};
	    
	    while(steps--) {
	        vector<vector<double>> ndp(N, vector<double>(N, 0.0));
	        for(int x = 0; x < N; x++) for(int y = 0; y < N; y++) {
	            for(int k = 0; k < 8; k++) {
	                int nx = x + X[k];
	                int ny = y + Y[k];
	                
	                if(nx >= 0 && ny >= 0 && nx < N && ny < N) 
	                    ndp[nx][ny] += dp[x][y] / 8;
	            }
	        }
	        
	        dp = ndp;
	    }
	    
	    double ans = 0.0;
	    for(auto it: dp) ans += accumulate(it.begin(), it.end(), 0.0);
	    
	    return ans;
	} 
