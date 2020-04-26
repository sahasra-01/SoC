#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const ll MAX = 300000;
ll dp[MAX], nChild[MAX], n;
vector<pair<ll,ll>> adj[MAX];

void dfsin(ll node, ll par){
	dp[node] = 0;

	for(ll i=0; i<adj[node].size(); i++){
		ll child = adj[node][i].first;
		if(child == par)
			continue;

		dfsin(child, node);
		dp[node] += dp[child];
		nChild[node] += nChild[child];
		dp[node] += nChild[child]*adj[node][i].second;
	}
}

void dfsout(ll node, ll par){
	for(ll i=0; i<adj[node].size(); i++){
		ll child = adj[node][i].first;
		if(child == par)
			continue;
		
		dp[child] = dp[node] + n*adj[node][i].second - 2*nChild[child]*adj[node][i].second;
		dfsout(child, node);		
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for(ll i=0; i<n; i++)
		nChild[i] = 1;

	ll u, v, w;
	for(ll i=1; i<n; i++){
		cin >> u >> v >> w;
		u--;	v--;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}

	dfsin(0,0);
	dfsout(0,0);

	for(ll i=0; i<n; i++)
		cout << dp[i] << " ";
	cout << '\n';
}