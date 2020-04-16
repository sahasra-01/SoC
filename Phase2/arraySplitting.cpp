#include <bits/stdc++.h>
using namespace std;

bool decres(pair <int,int> &a, pair <int,int> &b){
	return a.first > b.first;
}

bool post_sort(pair <int,int> &a, pair <int,int> &b){
	return a.second < b.second;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector < pair <int,int> > a(n);
	vector <bool> b(n, false);
	b[0] = true;

	int x;
	for(int i=0; i<n; i++){
		cin >> x;
		a[i].first = x;
		a[i].second = i;
	}

	sort(a.begin()+1, a.end(), decres);

	int i=0;
	while(i<n-k){
		
	}

}