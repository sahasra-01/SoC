#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void dfs(list<int> *adj, bool *visited, stack<int> &stk, int s, int *flag, int f){
	visited[s] = true;
	flag[s] = f;

	for(auto it=adj[s].begin(); it!=adj[s].end(); it++){
		if(!visited[*it])
			dfs(adj, visited, stk, *it, flag, f);
	}
	stk.push(s);
}

int dfs2(list<int> *adj, bool *visited, stack<int> &stk, int s, int *a){
	visited[s] = true;
	int sum=a[s];

	for(auto it=adj[s].begin(); it!=adj[s].end(); it++){
		if(!visited[*it])
			sum += dfs2(adj, visited, stk, *it, a);
	}
	stk.push(s);
	// cout << sum << '\n';
	return sum;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int a[n];
	for(int i=0; i<n; i++)
		cin >> a[i];

	list <int> adj[n];
	list <int> rev[n];
	// list <int> *final;
	bool visited[n];
	int flag[n];
	int finalans[n];

	int t1, t2;
	for(int i=0; i<m; i++){
		cin >> t1 >> t2;
		t1--;	t2--;
		adj[t1].push_back(t2);
		rev[t2].push_back(t1);
	}

	stack<int> s;

	memset(visited, false, n);
	memset(flag, -1, n);
	int f = 0;
	for(int i=0; i<n; i++){
		if(!visited[i]){
			// cout << "start dfs" << i << '\n';
			dfs(adj, visited, s, i, flag, f);
			f++;
		}
	}

	int src;
	vector <pair<int,int>> frnds;
	memset(visited, false, n);
	while(!s.empty()){
		src = s.top();
		s.pop();

		if(visited[src])
			continue;
		else{
			frnds.push_back({dfs2(rev, visited, s, src, a), flag[src]});
		}
	}
	// cout << f <<'\n';

	for(int i=0; i<frnds.size(); i++){
		cout << frnds[i].first << " ";
		cout << frnds[i].second << '\n';
	}

	if(frnds.size() == 1){
		cout << frnds[0].first << '\n';
		return 0;
	}

	// final = new list<int> [frnds.size()];
	list <int> final [frnds.size()];
	int num[frnds.size()];

	for(int i=0; i<frnds.size()-1; i++){

	}


}