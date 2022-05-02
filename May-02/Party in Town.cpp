https://practice.geeksforgeeks.org/problems/party-in-town3951/1#

int partyHouse(int N, vector<vector<int>> &adj){
        int ans = INT_MAX;
        for(int i = 1; i <= N; ++i) {
            queue<pair<int, int>> q;
            vector<bool> vis(N + 1, false);
            vis[i] = true;
            for(auto x : adj[i]) {
                q.push({x, 1});
                vis[x] = true;
            }
            int mxdis = 1;
            while(!q.empty()) {
                int fr = q.front().first;
                int dis = q.front().second;
                q.pop();
                
                mxdis = max(mxdis, dis);
                for(auto x : adj[fr]) {
                    if(!vis[x]) {
                      q.push({x, dis + 1});
                      vis[x] = true;  
                    }
                }
            }
            ans = min(ans, mxdis);
        }
        return ans;
    }
