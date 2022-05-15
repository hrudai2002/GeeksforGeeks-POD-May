vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        vector<vector<int>> ans;
        set<vector<int>> s;
        for(int i = 0; i < pow(2, n); ++i) {
            vector<int> a;
            for(int j = 0; j < n; ++j) {
                if(i & (1 << j)) a.push_back(arr[j]);
            }
            sort(a.begin(), a.end());
            s.insert(a);
        }
        for(auto i : s) ans.push_back(i);
        return ans;
    }
