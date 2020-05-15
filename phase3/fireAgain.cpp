#include<bits/stdc++.h>
#define ll long long int
// #define MAX 10000
using namespace std;

struct tree{
	int x=0, y=0, d=10000;
};

void left_tree(tree *burned, int n, int m, int k){
	bool visited[n][m];
	tree a[n][m];

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++){
			a[i][j].x = i;
			a[i][j].y = j;
		}
	
	// Loop to assign min distance of all the trees from the burning trees
	for(int t=0; t<k; t++){
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++){
				visited[i][j] = false;
			}

		tree s = burned[t];
		s.d = 0;
		a[s.x][s.y].d = 0;

		queue<tree> q;
		q.push(s);
		visited[s.x][s.y] = true;

		while(!q.empty()){
			tree p = q.front();
			q.pop();
			p.d = a[p.x][p.y].d;

			// cout << p.x << " here I am " << p.y << '\n';

			// moving up
			if(p.x-1>=0){
				if(visited[p.x-1][p.y]==false){
					q.push(a[p.x-1][p.y]);
					visited[p.x-1][p.y] = true;
					if(a[p.x-1][p.y].d > p.d+1)
						a[p.x-1][p.y].d = p.d+1;
				}
			}
			// moving down
			if(p.x+1 < n){
				if(visited[p.x+1][p.y]==false){
					q.push(a[p.x+1][p.y]);
					visited[p.x+1][p.y] = true;
					if(a[p.x+1][p.y].d > p.d+1)
						a[p.x+1][p.y].d = p.d+1;
				}
			}
			// moving left
			if(p.y-1>=0){
				if(visited[p.x][p.y-1]==false){
					q.push(a[p.x][p.y-1]);
					visited[p.x][p.y-1] = true;
					if(a[p.x][p.y-1].d > p.d+1)
						a[p.x][p.y-1].d = p.d+1;
				}
			}
			// moving right
			if(p.y+1 < m){
				if(visited[p.x][p.y+1]==false){
					q.push(a[p.x][p.y+1]);
					visited[p.x][p.y+1] = true;
					if(a[p.x][p.y+1].d > p.d+1)
						a[p.x][p.y+1].d = p.d+1;
				}
			}
		}
	}

	tree max;
	max.d=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			// cout << a[i][j].d << " ";
			if(a[i][j].d > max.d){
				max = a[i][j];
			}
		}
		// cout << endl;
	}

	cout << max.x+1 << " " << max.y+1 << '\n';
}

int main(){
	freopen("input.txt","r",stdin); 
	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int k;
	cin >> k;

	tree burned[k];

	int a, b;
	for(int i=0; i<k; i++){
		cin >> a >> b;
		a--;	b--;
		burned[i].x = a;
		burned[i].y = b;
	}

	left_tree(burned, n, m, k);
}