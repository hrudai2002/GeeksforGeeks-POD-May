vector<int> farNumber(int N,vector<int> a){
       vector<pair<int, int>> v;
       v.push_back({a[N - 1], N - 1});
       a[N - 1] = -1;
       for(int i = N - 2; i >= 0; --i) {
           int mx = -1, low = 0, high = v.size() - 1;
           while(low <= high) {
               int mid = low + (high - low)/2;
               if(v[mid].first < a[i]) {
                   mx = max(mx, v[mid].second);
                   high = mid - 1;
               }
               else {
                   low = mid + 1;
               }
           }
           if(mx == -1) 
             v.push_back({a[i], i});
          a[i] = mx;
       }
       return a;
    }
