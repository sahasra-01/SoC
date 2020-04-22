#include <bits/stdc++.h>
#define p 998244353
using namespace std;
int ans=0;

void permut(vector<pair<int,int>> &in, vector<pair<int,int>> &out, int i, long int temp, int k){
	// similar to C(n, 0)
	if(out.size() >= k){
		ans += temp;
		ans %= p;
		return;
	}

	// similar to C(n, n)
	if(in.size()-i == k-out.size()){
		for(int j=i; j<in.size(); j++){
			temp *= in[j].second;
			temp %= p;
		}
		ans += temp;
		ans %= p;
		return;
	}

	// end of elements
	if(i >= in.size()){
		return;
	}

	// in[i] not selected
	permut(in, out, i+1, temp, k);
	
	out.push_back(in[i]);
	temp *= in[i].second;
	temp %= p;

	// in[i] selected
	permut(in, out, i+1, temp, k);
	out.pop_back();				// Backtracking
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	map <int, int> m;
	vector< pair<int,int> > a;

	int t1;
	for(int i=0; i<n; i++){
		cin >> t1;
		m[t1]++;
	}

	for(auto it=m.begin(); it!=m.end(); it++){
		a.push_back({it->first, it->second});
	}

	vector< pair<int,int> > out;

	long int t=1;
	permut(a, out, 0, t, k);

	cout << ans << '\n';
}