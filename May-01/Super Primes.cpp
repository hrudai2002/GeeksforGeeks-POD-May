https://practice.geeksforgeeks.org/problems/super-primes2443/1#


nt prime[100001];
	void sie(int n) {
	    memset(prime, 1, sizeof(prime));
	    prime[0] = prime[1] = 0;
	    for(int i = 2; i*i <= n; ++i) {
	        if(prime[i])
	           for(int j = i*i; j <= n; j += i)
	               prime[j] = 0;
	    }
	}
	int superPrimes(int n)
	{
	    sie(n);
	    int count = 0;
	    vector<int> a;
	    for(int i = 1; i <= 100001; ++i)
	       if(prime[i]) a.push_back(i);
	    int i = -1;
	    while(a[++i] <= n);
	    
	    for(int x = i - 1; x > 0; --x) {
	        if(prime[a[x] - a[x - 1]]){
	            count++;
	        }  
	    }
	    return count;
	}
