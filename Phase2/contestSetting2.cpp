#include <bits/stdc++.h>
#define ll long long int
#define p 998244353
using namespace std;

ll f(vector <ll> &a, int n, int i, int j){
	if(j==0)
		return 1;
	if(i == 0)
		return 0;

	return (f(a, n, i-1, j-1)*a[i-1]+f(a, n, i-1, j))%p;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, k;
	cin >> n >> k;

	map <ll, ll> m;
	vector< ll > a;

	ll t1;
	for(ll i=0; i<n; i++){
		cin >> t1;
		m[t1]++;
	}

	for(auto it=m.begin(); it!=m.end(); it++){
		a.push_back(it->second);
	}

	/*for(auto it=a.begin(); it!= a.end(); it++)
		cout << it->second << " ";
	cout << '\n';*/

	ll t = f(a, a.size(), a.size(), k);

	// ll t = pascal(a, a.size(), k);

	cout << t%p << '\n';
}