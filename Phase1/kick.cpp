// https://wnccsoc.slack.com/files/U010HBPDA0G/F010T3W828G/prob-l4b-b.pdf.pdf

#include <bits/stdc++.h>
using namespace std::chrono;
using namespace std;

int pos_post;

int solve(){
	pos_post = 0;

	// int n = 100000;
	int n;
	cin >> n;

	pair <int, int> a[n];

	int x;
	int max = 0;
	for(int i=0; i<n; i++){
		cin >> x;
		// x = i*10000;
		if(max < x)
			max = x;

		a[i] = {x, i+1};
	}

	sort(a, a+n);

	int cnt=0, post=0, temp=0;

	while(true){
		cnt++;

		temp += a[pos_post].second;

		for(int i=pos_post; i<n; i++){
			if(a[i].first >= temp){
				pos_post = i;
				break;
			}
			if(i == n-1)
				return cnt;
		}
	}

	return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	auto start = high_resolution_clock::now();

	int T;
	// cin >> T;
	T = 1;
	while(T--){
		cout << solve() << '\n';
	}
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);
	cout << duration.count() << endl;
}