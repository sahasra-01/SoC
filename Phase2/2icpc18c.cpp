#include <bits/stdc++.h>
#define p 998244353
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	map <int, int> m;
	vector <int> a;

	int t1;
	for(int i=0; i<n; i++){
		cin >> t1;
		m[t1]++;
	}

	for(auto it=m.begin(); it!=m.end(); it++){
		a.push_back(it->second);
	}

	vector<bool> v(a.size());

	if(k > a.size()){
		cout << 0 << '\n';
		return 0;
	}

	fill(v.begin(), v.begin()+k ,true);
	long int ans=0;

	do{
		int temp = 1;
		for(int i=0; i<a.size(); i++){
			if(v[i]){
				temp *= a[i];
				temp %= p;
			}
		}
		ans += temp;
		ans %= p;
	}while(prev_permutation(v.begin(), v.end()));


	cout << ans%p << '\n';
	return 0;
}