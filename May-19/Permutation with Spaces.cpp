vector<string> subset;
    bool check(string curr, string s) {
        int it = 0;
        for(int i = 0; i < curr.size(); ++i) {
            if(curr[i] != ' ') {
                if(curr[i] != s[it]) return false;
                else it++;
            }
        }
        return it == s.size() ? true : false;
    }
    void subsets(string s, string curr, int i, int n, string org) {
        if(i == n) {
            if(check(curr, org))
            subset.push_back(curr);
            return;
        }
        subsets(s, curr + s[i], i + 1, n, org);
        subsets(s, curr, i + 1, n, org);
    }
    vector<string> permutation(string s){
        string res = "";
        for(int i = 0; i < s.size(); ++i) {
            if(i < s.size() - 1)
            res += s[i], res += " ";
            else res += s[i];
        }
        subsets(res, "", 0, res.size(), s);
        sort(subset.begin(), subset.end());
        return subset;
    }
