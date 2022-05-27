    vector<int> numAndDen(int n, int d) {
        double num = (double)n / (double)d;
       vector<int>ans;
       double mx = 0;
       for(int i=2 ; i<10000 ; i++)
       {
           int j = n * i / d;
           double num2 = (double)j / (double)i;
           if(num2 < num  && mx < num2 && __gcd(i , j) == 1)
           {
               mx = num2;
               ans = {j , i};
           }
       }
       return ans;
    }
