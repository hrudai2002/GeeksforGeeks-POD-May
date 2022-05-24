bool partitionArray(int N, int K, int M, vector<int> &A){
         // code here
        sort(A.begin(),A.end());
        A.insert(A.begin(),0);
        vector<int> dp(A.size(),0);
        dp[0] = 1;
        vector<int> pre(A.size(),0);
        pre[0] = 1;
        for(int i=1; i<A.size(); i++)
        {
            int l1 = lower_bound(begin(A),end(A),A[i] - M) - A.begin();
            int l2 = i - K + 1;
            int cur = 0;
            if(l2 > 0) cur += pre[l2-1];
            if(l1 >=2) cur -= pre[l1-2];
            if(cur > 0) dp[i] = 1;
            pre[i] = pre[i-1] + dp[i];
        }
        return dp[A.size()-1];
    }
