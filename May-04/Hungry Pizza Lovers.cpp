https://practice.geeksforgeeks.org/problems/hungry-pizza-lovers3148/1

vector<int> permute(vector<vector<int>> &arr, int n)
{
    vector<pair<int, int>> res;
    for(int i = 0; i < n; ++i) {
        res.push_back({arr[i][0] + arr[i][1], i + 1});
    }
    sort(res.begin(), res.end());
    vector<int> ans;
    for(auto i : res) 
       ans.push_back(i.second);
    return ans;
}
