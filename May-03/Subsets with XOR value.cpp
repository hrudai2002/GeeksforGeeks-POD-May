https://practice.geeksforgeeks.org/problems/subsets-with-xor-value2023/1#

 int solve(vector<int> &arr , int N , int K){
       if(N == 0){
           return K == 0;
       }
       int take = solve(arr , N - 1 , K ^ arr[N - 1]);
       int leave = solve(arr , N - 1 , K);
       return take + leave;
   }
   int subsetXOR(vector<int> &arr, int N, int K) {
       // code here
       return solve(arr , N , K);
   }
