int transform (string A, string B)
    {
        if(A.length() != B.length()) return -1;
        
        unordered_map<char,int> freq;
        
        for(int i = 0; i < A.length(); i++) {
            freq[A[i]]++;
        }
        
        for(int i = 0; i < B.length(); i++) {
            freq[B[i]]--;
        }
        
        for(auto x: freq) {
            if(x.second != 0) return -1;
        }
        
        int j = B.length()-1;
        
        for(int i = A.length()-1; i >= 0; i--) {
            if(A[i] == B[j])
                j--;
        }
        
        return j+1;
    }
