#include <bits/stdc++.h>
using namespace std;

int solve(){
	int r, c, k;
	cin >> r >> c >> k;
	r--;	c--;

	int ans = 0;
	vector <vector<int>> board(8, vector<int>(8, 0));
	board[r][c] = 1;

	for(int t=0; t<k; t++){
		
	}
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