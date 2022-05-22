string findAndReplace(string s ,int Q, int index[], string sources[], string targets[]) {
        unordered_map<int, string> mp;
        for(int i = 0; i < Q; ++i) {
            string src = s.substr(index[i], sources[i].size());
            if(src == sources[i]) {
               mp[index[i]] =  targets[i];
               for(int j = index[i] + 1; j < index[i] + sources[i].size(); ++j) {
                   mp[j] = "-1";
               }
            }
        }
        string ans = "";
        for(int i = 0; i < s.size(); ++i) {
            if(mp.find(i) == mp.end()) ans += s[i];
            else {
                if(mp[i] != "-1") ans += mp[i];
            }
        }
        return ans;
    }
