#include <bits/stdc++.h>
using namespace std;

int solve(){
	int x, y;
	cin >> x >> y;

	if(x > y){
		return x-y;
	}if(x == y){
		return 0;
	}

	int cnt=0;
	while(x!=y){
		cnt++;
		if(y<x){
			return cnt+x-y-1;
		}

		if(y%2){
			y++;
		}else{
			y=y/2;
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