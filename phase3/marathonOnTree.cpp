#include <bits/stdc++.h>
#define ll long long int 
using namespace std; 


ll pow_2(ll i){
	ll ans=1;
	for(int j=0; j<i; j++){
		ans = ans << 1;
	}
	return ans;
}

// Pre-processing to calculate values of memo[][] 
void dfs(ll u, ll p, ll **memo, ll *lev, ll log, vector<ll> *g) 
{ 
	// Using recursion formula to calculate 
	// the values of memo[][] 
	memo[u][0] = p; 
	for (ll i = 1; i <= log; i++) 
		memo[u][i] = memo[memo[u][i - 1]][i - 1]; 
	for (ll v : g[u]) 
	{ 
		if (v != p) 
		{ 
			lev[v] = lev[u] + 1; 
			dfs(v, u, memo, lev, log, g); 
		} 
	} 
} 

// Function to return the LCA of nodes u and v 
ll lca(ll u, ll v, ll log, ll *lev, ll **memo) 
{ 
	// The node which is present farthest 
	// from the root node is taken as u 
	// If v is farther from root node 
	// then swap the two 
	if (lev[u] < lev[v]) 
		swap(u, v); 

	// Finding the ancestor of u 
	// which is at same level as v 
	for (ll i = log; i >= 0; i--) 
		if ((lev[u] - pow(2, i)) >= lev[v]) 
			u = memo[u][i]; 

	// If v is the ancestor of u 
	// then v is the LCA of u and v 
	if (u == v) 
		return u; 

	// Finding the node closest to the root which is 
	// not the common ancestor of u and v i.e. a node 
	// x such that x is not the common ancestor of u 
	// and v but memo[x][0] is 
	for (ll i = log; i >= 0; i--) 
	{ 
		if (memo[u][i] != memo[v][i]) 
		{ 
			u = memo[u][i]; 
			v = memo[v][i]; 
		} 
	} 

	// Returning the first ancestor 
	// of above found node 
	return memo[u][0]; 
} 

// Driver Code 
int main() 
{ 
	// Number of nodes 
	ll n, q;
	cin >> n >> q;

	// vector to store tree 
	vector<ll> g[n + 1]; 

	ll log = (ll)ceil(log2(n)); 
	ll **memo = new ll *[n + 1]; 
	for (ll i = 0; i < n + 1; i++) 
		memo[i] = new ll[log + 1]; 

	// Stores the level of each node 
	ll *lev = new ll[n + 1]; 

	// Initialising memo values with -1 
	for (ll i = 0; i <= n; i++) 
		memset(memo[i], -1, sizeof memo[i]); 

	// Add edges
	ll a, b;
	for(ll i=0; i<n-1; i++){
		cin >> a >> b;
		a--;	b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(1, 1, memo, lev, log, g); 

	ll c;
	for(ll i=0; i<q; i++){
		cin >> a >> b >> c;
		a--;	b--;	c--;
		ll x = lca(a, b, log, lev, memo);
		ll y = lca(a, c, log, lev, memo);
		ll z = lca(b, c, log, lev, memo);

		if((z==x && y==c)||(y==x&&z==c)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0; 
} 
