bool cmp(pair<int, int> a, pair<int, int> b) {
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
}
class Solution {
public:
    vector<int> maximizeArray(int arr1[], int arr2[], int n) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            unordered_map<int, int> mp;
            vector<pair<int, int>> ar1;
            for(int i = 0; i < n; ++i) {
                if(mp.find(arr2[i]) == mp.end()) {
                    pq.push({arr2[i], i});
                    mp[arr2[i]] = 1;
                }
            }
            for(int i = 0; i < n; ++i) {
                ar1.push_back({arr1[i], i});
            }
            sort(ar1.rbegin(), ar1.rend(), cmp);
            for(int i = 0; i < n; ++i) {
                if(pq.top().first < ar1[i].first && mp.find(ar1[i].first) == mp.end()) {
                    if(pq.size() == n)  {
                         mp[pq.top().first] = 0;
                         pq.pop();
                    }
                    pq.push({ar1[i].first, n + ar1[i].second});
                    mp[ar1[i].first] = 1;
                }
            }
            if(pq.size() < n) {
                for(int i = 0; i < n && pq.size() < n; ++i) {
                    if(mp.find(ar1[i].first) == mp.end()){
                        pq.push({ar1[i].first, n + ar1[i].second});
                        mp[ar1[i].first] = 1;
                    } 
                }
            }
            vector<pair<int, int>> ans;
            while(!pq.empty()) {
                ans.push_back({pq.top().second, pq.top().first});
                pq.pop();
            }
            sort(ans.begin(), ans.end());
            vector<int> res;
            for(auto i : ans) res.push_back(i.second);
            return res;
    }
};
