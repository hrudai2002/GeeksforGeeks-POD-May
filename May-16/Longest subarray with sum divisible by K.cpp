int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    unordered_map<int, int> mp;
	    vector<int> prefixsum(n, 0);
	    prefixsum[0] = arr[0];
	    int maxlen = 0, rem;
	    for(int i = 1; i < n; ++i)
	       prefixsum[i] = arr[i] + prefixsum[i - 1];
	    for(int i = 0; i < n; ++i) {
	        if(prefixsum[i] % k == 0) maxlen = max(maxlen, i + 1);
	        if(i > 0) {
	            rem = prefixsum[i]%k;
	            if(rem < 0) rem = rem += k;
	            if(mp.find(rem) != mp.end()) {
	                maxlen = max(maxlen, i - mp[rem]);
	            }
	        }
	        rem = prefixsum[i]%k;
	        if(rem < 0) rem = rem += k;
	        if(mp.find(rem) == mp.end()) {
	            mp[rem] = i;
	        }
	    }
	    return maxlen;
	}
