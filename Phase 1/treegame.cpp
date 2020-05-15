#include <bits/stdc++.h>
using namespace std;
int mdep = 0;

class node{
public:
	node *parent;
	vector <node *> child;
	int n_child;
	int depth;

	node(){
		parent = new node();
		child.push_back(new node());
		n_child = 0;
		depth = 0;
	}

	void nc(){
		n_child++;
		child.push_back(new node());
	}

	void fixd(int x){
		depth = x;
	}
};

void assign_depth(node **t, int cur, node *par){
	t[cur]->fixd( ( par->depth ) + 1 );

	if(mdep < t[cur]->depth)
		mdep = t[cur]->depth;

	for(int i=0; i<t[cur]->n_child; i++){
		assign_depth(t, i, t[cur]);
	}
}

int solve(){
	int n;
	cin >> n;

	node *t[n];

	for(int i=0; i<n; i++)
		t[i] = new node();

/*
	int a, b;
	for(int i=0; i<n-1; i++){
		cin >> a >> b;
		a--; b--;

		t[b]->parent = t[a];

		t[a]->child[t[a]->n_child] = t[b];

		t[a]->nc();
	}

*/
	int dcnt[mdep];

	if(n > 1)
		assign_depth(t, 1, t[0]);


	for(int i=0; i<n; i++){
		dcnt[ t[i]->depth ]++;
	}

	for(int i=0; i<n; i++){
		cout << t[i]->depth << " ";
	}

	int ans=0;
	int c_dep=0;

	

	for(int i=0; i<n; i++){
		if(i%2 == 0){
			c_dep ++;
			ans++;
			if(mdep == c_dep){
				if(dcnt[mdep] == 1)
					return ans+1;
				else
					return ans+2;
			}
		}else{
			dcnt[mdep]--;
			if(dcnt[mdep] == 0) mdep--;
			ans++;
			if(mdep == c_dep)
				return ans+1;
		}
	}

	return ans;
	return 0;
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
