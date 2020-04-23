#include <bits/stdc++.h>
using namespace std;

int bsearch(int *a, int i, int j, int g, int prev){
	// cout << "inp: " << i << ' ' << j << ' ' << g << '\n';
	while(i < j){
	// cout << "inp: " << i << ' ' << j << ' ' << g << '\n';

		int temp = (i+j)>>1;

		if(a[temp]-prev <= g)
			i = temp+1;
		else
			j=temp;
	}

	return i-1;
}

int solve(){
	int n, k;
	cin >> n >> k;

	int a[n+1];
	for(int i=0; i<n; i++)
		cin >> a[i];
	a[n] = a[n-1]+1;

	sort(a, a+n);

	vector <int> cows;
	cows.push_back(0);

	int gap = (a[n-1]-a[0])/(k-1);
	int temp, last=0;

	for(int i=1; i<k; i++){
		if(a[last+1]-a[last] >= gap)
			temp = last+1;
		else
			temp = bsearch(a, last, n, gap, a[last]);
		cows.push_back(temp);
		last = temp;
	} 	

	/*for(int i=0; i<k; i++){
		cout << a[cows[i]] << " ";
	}cout << '\n';*/

	int ans = a[cows[1]]-a[cows[0]];

	for(int i=2; i<k; i++){
		int temp = a[cows[i]]-a[cows[i-1]];
		if(ans > temp)
			ans = temp;
	}

	return ans;
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