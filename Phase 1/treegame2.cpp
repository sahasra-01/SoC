#include <bits/stdc++.h>
using namespace std;

class node{
	vector <int> child;
public:
	int depth;
	void add(int a){
		child.push_back(a);
	}
	bool no_child(){
		if(child.size==0)
			return true;
		else
			return false;
	}
};

int finddep(node *a, int i){
	if(no_child)
		return 0;
	else{
		return a[i].depth+1;
	}
}

int solve(){
	int n;
	cin >> n;

	node a[n];

	int t1, t2;
	for(int i=0; i<n-1; i++){
		cin >> t1 >> t2;
		t1--; t2--;
		a[t1].add(t2);
	}

	for(int i=n-1; i>=0; i--){
		a[i].depth = finddep(a, i);
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