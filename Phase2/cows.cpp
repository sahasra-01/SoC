	#include <bits/stdc++.h>
	using namespace std;

	bool possible(int *a, int n, int x, int k){
		int cnt=1;
		int last = a[0];

		for(int i=1; i<n; i++){
			if(a[i]-last >= x){
				cnt++;
				last = a[i];
			}
			if(cnt == k){
			// cout << last << " " << i << '\n';
				return true;
			}
		}

		if(cnt < k)
			return false;
		return true;
	}

	int solve(){
		int n, k;
		cin >> n >> k;

		int a[n];
		for(int i=0; i<n; i++)
			cin >> a[i];

		sort(a, a+n);

		int gap = (a[n-1]-a[0])/(k-1);
		int i=0, j=gap+1;

		while(i<j){
			// cout << "   " << i << " " << j << '\n';
			int mid = (i+j)>>1;
			if(!possible(a, n, mid, k)){
				j=mid;
			}
			else{
			// cout << " hello\n";
				i=mid+1;
			}
		}

		return i-1;
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