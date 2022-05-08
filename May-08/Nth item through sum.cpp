https://practice.geeksforgeeks.org/problems/nth-item-through-sum3544/1

int nthItem(int L1, int L2, int A[], int B[], int N)
    {
        set<int> ans;
        for(int i = 0; i < L1; ++i) {
            for(int j = 0; j < L2; ++j) {
                ans.insert(A[i] + B[j]);
            }
        }
        int n = 0;
        for(auto i : ans) {
            n += 1;
            if(n == N) 
              return i;
        }
        return -1;
    }
