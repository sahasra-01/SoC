#include <bits/stdc++.h>
using namespace std;

struct node{
	int **edge;
	vector <int> children;
	vector < map<int,int> > sum;
};

class Tree{
	int N;
	node *a;

public:
	Tree(int n){
		this->N = n;
		a = new int[n];

		egde = new int *[n];
		for(int i=0; i<n; i++)
			egde[i] = new int [n];

		

	}

	void addEdge(int u, int v, int w){
		edge[u][v] = w;
		egde[v][u] = w;
	}


};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int u, v, w;
	for(int i=1; i<n; i++){
		cin >> u >> v >> w;
	}
}