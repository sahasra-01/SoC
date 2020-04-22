#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll cnt(ll x, ll i, ll m){
	return min((x-1)/i, m);	//check
}

ll check(ll n, ll x, ll m){
	ll sum=0;
	for(ll i=1; i<=n; i++){
		sum += cnt(x, i, m);
	}
	return sum;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m, k;
	cin >> n >> m >> k;

	ll i=1, j=n*m+1;

	while(i<j){
		ll temp = (i+j)/2;

		if(check(n, temp, m) < k)
			i = temp+1;
		else
			j = temp;
	}

	cout << i-1 << '\n';
}