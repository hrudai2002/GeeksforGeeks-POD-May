vector<int> findOrder(int n, int m, vector<vector<int>> preq) 
    {
        vector<int> ans, indegree(n + 1, 0);
        vector<int> adj[n + 1];
        for(int i = 0; i < preq.size(); ++i) {
            indegree[preq[i][0]]++;
            adj[preq[i][1]].push_back(preq[i][0]);
        }
        queue<int> q;
        for(int i = 0; i < n; ++i) {
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto i : adj[node]) {
                indegree[i]--;
                if(indegree[i] == 0) q.push(i);
            }
        }
        if(ans.size() < n) return {};
        return ans;
    }
