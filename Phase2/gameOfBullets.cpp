#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;

	int a[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
	}

	int nim_sum=a[0];

	for(int i=1; i<n; i++){
		nim_sum = nim_sum^a[i];
	}

	if(nim_sum==0){
		cout << "Isa\n";
	}else
		cout << "Gaitonde\n";

	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while(T--){
		solve();
	}
}