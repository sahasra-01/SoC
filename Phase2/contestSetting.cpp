#include <bits/stdc++.h>
#define ll long long int
const ll p { 998244353 } ;
using namespace std;

void pascal(vector <pair<ll,ll>> &a, ll n, ll k){
	ll psc[n+1][n+1];
	psc[0][0] = 1;

	for(ll line=1; line<=n; line++){
		for(ll i=0; i<=line; i++){
			if(i==line){
				psc[line][i] = ( (a[line-1].second)*(psc[line-1][line-1]) )%p;
			}
			
			else if(i == 0)
				psc[line][i] = 1;
			
			else{
				psc[line][i] = ( (psc[line-1][i-1])*(a[line-1].second) + psc[line-1][i] )%p;
			}
			
			// psc[line][i-1] %= p;
			// cout << psc[line][i] << " ";
		}
		// cout << '\n';
	}

	cout << ((psc[n][k])%p) << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, k;
	cin >> n >> k;

	if(n == 0){
		cout << "0\n";
		return 0;
	}

	map <ll, ll> m;
	vector< pair<ll,ll> > a;

	ll t1;
	for(ll i=0; i<n; i++){
		cin >> t1;
		m[t1]++;
	}

	for(auto it=m.begin(); it!=m.end(); it++){
		a.push_back({it->first, it->second});
	}

	if(k > a.size()){
		cout << "0\n";
		return 0;
	}
/*
	for(auto it=a.begin(); it!= a.end(); it++)
		cout << it->second << " ";
	cout << '\n';*/

	pascal(a, a.size(), k);

}