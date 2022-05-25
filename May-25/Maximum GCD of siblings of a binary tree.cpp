int maxBinTreeGCD(vector<vector<int>> arr, int N) {
       int ans = 0;
       sort(arr.begin(), arr.end());
       for(int i = 1; i < N - 1; ++i) {
          if(arr[i][0] == arr[i - 1][0]){
              ans = max(ans, __gcd(arr[i][1], arr[i - 1][1]));
          }
       } 
       return ans;
    }
