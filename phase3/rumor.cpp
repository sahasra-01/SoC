#include <bits/stdc++.h>
#define ll long long unsigned int
using namespace std;

class Graph{
	ll V;
	list <ll> *adj;
	bool *done;
	ll *bribe;
	vector <ll> minim;
	ll DFSUtil(ll v, bool *visited, ll depth);
public:
	Graph(ll vertices);
	void setBribe(ll *a);
	void addEdge(ll v, ll w);
	void dfs();
	ll topay();
};

Graph::Graph(ll vertices){
	this->V = vertices;
	adj = new list<ll>[V];
	done = new bool [V];
	bribe = new ll [V];
}

ll Graph::DFSUtil(ll v, bool *visited, ll depth){
	visited[v] = true;
	if(depth > 0)
		done[v] = true;

	vector <ll> temp;

	for(auto it = adj[v].begin(); it!=adj[v].end(); it++)
		if(!visited[*it])
			temp.push_back( DFSUtil(*it, visited, depth+1) );

	if(temp.empty())
		return bribe[v];

	sort(temp.begin(), temp.end());
	return min( temp[0], bribe[v] );
}
void Graph::setBribe(ll *a){
	// Check for TLE
	for(ll i=0; i<V; i++)
		bribe[i] = a[i];
}

void Graph::addEdge(ll v, ll w){
	adj[v].push_back(w);
	adj[w].push_back(v);
}

void Graph::dfs(){
	bool *visited = new bool[V];
	for(ll i=0; i<V; i++){
		visited[i] = false;
		done[i] = false;
	}

	// ll temp_min=INT_MAX;
	for(ll i=0; i<V; i++){
		if(visited[i] == false){
			minim.push_back( DFSUtil(i, visited, 0) );
		}
	}

	// DFSUtil(v, visited);
}	

ll Graph::topay(){
	ll ans = 0;
	/*for(ll i=0; i<V; i++){
		// cout << " " << i << " " << done[i] << '\n';
		if(done[i] == false){
			ans += bribe[i];
		}
	}*/
	for(int i=0; i<minim.size(); i++){
		// cout << minim[i] << " ";
		ans +=  minim[i];
	}

	return ans;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, f;
	cin >> n >> f;

	ll a[n];
	for(ll i=0; i<n; i++){
		cin >> a[i];
	}

	Graph g(n);
	g.setBribe(a);

	ll t1, t2;
	for(ll i=0; i<f; i++){
		cin >> t1 >> t2;
		t1--;	t2--;
		g.addEdge(t1, t2);
	}

	g.dfs();

	cout << g.topay() << '\n';
}