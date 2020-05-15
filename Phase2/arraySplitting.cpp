#include <bits/stdc++.h>
using namespace std;

bool decr(long long int &a, long long int &b){
	return a>b;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long int n, k;
	cin >> n >> k;

	long long int a[n];
	long long int suff[n];

	for(long int i=0; i<n; i++){
		cin >> a[i];
	}

	suff[n-1] = a[n-1];
	for(long int i=n-2; i>=0; i--){
		suff[i] = suff[i+1] + a[i];
	}

	sort(suff+1, suff+n, decr);

	long long int ans = suff[0];

	for(long long int i=1; i<k; i++){
		ans += suff[i];
	}

	cout << ans << '\n';
	return 0;
}