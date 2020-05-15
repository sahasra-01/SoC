#include <bits/stdc++.h>
using namespace std;

int solve(){
	int n;
	cin >> n;

	string s;
	cin >> s;

	int cnt=0;
	for(int i=1; i<n; i++){
		if(s[i] != s[i-1]){
			cnt++;
			i++;
		}
	}

	return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while(T--){
		cout << solve() << '\n';
	}
}