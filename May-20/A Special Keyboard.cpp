int findTime(string S1, string S2) {
        unordered_map<char, int> key;
        for(int i = 0; i < S1.size(); ++i)
           key[S1[i]] = i;
        int curr = 0, mntime = 0;
        for(int i = 0; i < S2.size(); ++i) {
            mntime += abs(curr - key[S2[i]]);
            curr = key[S2[i]];
        }
        return mntime;
    }
