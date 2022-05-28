int shortestPath( int x, int y){ 
         int mx = max(x, y), mn = min(x, y), ans = 0;
         while(mx != mn) {
             mx >>= 1;
             ans += 1;
             if(mx < mn) {
                 mn >>= 1;
                 ans += 1;
             }
         }
         return ans;
    }
