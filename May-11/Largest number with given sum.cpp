string largestNumber(int n, int sum)
    {
        if(9*n < sum)
          return "-1";
        string ans = "";
        for(int i = 0; i < n; ++i){
            if(sum >= 9) ans += "9", sum -= 9;
            else ans += to_string(sum), sum = 0;
        }
        return ans;
    }
