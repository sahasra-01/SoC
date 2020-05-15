#include <bits/stdc++.h>
using namespace std;

bool solve(){
	int n;
	cin >> n;

	int a[n];
	for(int i=0; i<n; i++)
		cin >> a[i];

	sort(a, a+n);

	for(int i=1; i<n; i++){
		if(a[i]-a[i-1] > 1)
			return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while(T--){
		bool b = solve();
		if(b)
			cout << "YES\n";
		else 
			cout << "NO\n";
	}
}