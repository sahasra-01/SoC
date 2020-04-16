#include <bits/stdc++.h>
#define p 998244353
using namespace std;
int ans=0;

void permut(vector<pair<int,int>> in, vector<pair<int,int>> out, int i, long int temp, int k){
	if(out.size() >= k){
		ans += temp;
		ans %= p;
		return;
	}
	if(i - out.size() > in.size()-k)
		return;
	if(i >= in.size())
		return;

	permut(in, out, i+1, temp, k);
	out.push_back(in[i]);
	temp *= in[i].second;
	temp %= p;
	// add mod thing
	permut(in, out, i+1, temp, k);
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