#include <iostream> 
#include <list> 
#include <vector>
#include <stack> 
#define ll long long int
using namespace std; 

class Graph{
	int V;
	list <int> *adj;
	int *friends;
	int *flag;
    vector <ll> sorted;
    int *dp;

    void topologicalSortUtil(ll v, bool visited[], stack<ll> &Stack); 
	void fillOrder(int v, bool visited[], stack<int> &Stack); 
	void DFSUtil(int v, bool visited[], int part, vector<vector<int>> &cnct); // A recursive function to print DFS starting from v  
public: 
	Graph(int V); 
	void addEdge(int v, int w); 
	void addFriends(int *a);
	void printSCCs(); // The main function that finds and prints strongly connected components
	Graph getTranspose(); // Function that returns reverse (or transpose) of this graph 
	void print();
    void topologicalSort();
    void calc();

};

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V];
	friends = new int[V];
	flag = new int[V];
	dp = new int[V];
}

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); // Add w to v’s list. 
}

void Graph::addFriends(int *a){
	for(int i=0; i<V; i++){
		friends[i] = a[i];
	}
} 

void Graph::printSCCs() 
{ 
	stack<int> Stack; 

	// Mark all the vertices as not visited (For first DFS) 
	bool *visited = new bool[V]; 
	for(int i = 0; i < V; i++) 
		visited[i] = false; 

	// Fill vertices in stack according to their finishing times 
	for(int i = 0; i < V; i++) 
		if(visited[i] == false) 
			fillOrder(i, visited, Stack); 

	// Create a reversed graph 
	Graph gr = getTranspose(); 

	// Mark all the vertices as not visited (For second DFS) 
	for(int i = 0; i < V; i++) 
		visited[i] = false; 

	vector<vector<int>> cnct(V);

	// Now process all vertices in order defined by Stack 
	int part=0;
	while (Stack.empty() == false) 
	{ 
		// Pop a vertex from stack 
		int v = Stack.top(); 
		Stack.pop();

		// Print Strongly connected component of the popped vertex 
		if (visited[v] == false) 
		{ 
			gr.DFSUtil(v, visited, part, cnct); 
		} 
		part++;
	}

	Graph gf(part);

	int tf[part];
	for(int i=0; i<part; i++){
		if(i!=part-1)
			gf.addEdge(i, i+1);
		tf[i] = 0;
		for(int j=0; j<cnct[i].size(); j++){
			tf[i] += cnct[i][j];
		}
	}

	gf.addFriends(tf);
	gf.topologicalSort();
	gf.calc();
}

void Graph::calc(){
	for(int i=V-1; i>=0; i--){
		dp[sorted[i]] = friends[sorted[i]];
		int max = 0;
    	for(auto it = adj[sorted[i]].begin(); it!=adj[sorted[i]].end(); it++){
            if(dp[*it]>max){
            	max = dp[*it];
            }
    	}
    	dp[sorted[i]] += max;
        cout << " " << sorted[i] << " " << dp[sorted[i]] << '\n';
	}
}


void Graph::topologicalSortUtil(ll v, bool visited[],  
                                stack<ll> &Stack) 
{ 
    // Mark the current node as visited. 
    visited[v] = true; 
  
    // Recur for all the vertices adjacent to this vertex 
    list<ll>::iterator i; 
    for (auto i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            topologicalSortUtil(*i, visited, Stack); 
  
    // Push current vertex to stack which stores result 
    Stack.push(v); 
} 
  
// The function to do Topological Sort. It uses recursive  
// topologicalSortUtil() 
void Graph::topologicalSort() 
{ 
    stack<ll> Stack; 
  
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for (ll i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Call the recursive helper function to store Topological 
    // Sort starting from all vertices one by one 
    for (ll i = 0; i < V; i++) 
      if (visited[i] == false) 
        topologicalSortUtil(i, visited, Stack); 
  
    // Prll contents of stack 
    while (Stack.empty() == false) 
    { 
        sorted.push_back(Stack.top());
        Stack.pop(); 
    } 
}

void Graph::fillOrder(int v, bool visited[], stack<int> &Stack) 
{ 
	// Mark the current node as visited and print it 
	visited[v] = true; 

	// Recur for all the vertices adjacent to this vertex 
	list<int>::iterator i; 
	for(i = adj[v].begin(); i != adj[v].end(); ++i) 
		if(!visited[*i]) 
			fillOrder(*i, visited, Stack); 

	// All vertices reachable from v are processed by now, push v 
	Stack.push(v); 
}


Graph Graph::getTranspose() 
{ 
	Graph g(V); 
	for (int v = 0; v < V; v++) 
	{ 
		// Recur for all the vertices adjacent to this vertex 
		list<int>::iterator i; 
		for(i = adj[v].begin(); i != adj[v].end(); ++i) 
		{ 
			g.adj[*i].push_back(v); 
		} 
	} 
	return g; 
} 

// A recursive function to print DFS starting from v 
void Graph::DFSUtil(int v, bool visited[], int part, vector<vector<int>> &cnct) 
{ 
	// Mark the current node as visited and print it 
	visited[v] = true;
	cnct[part].push_back(v);

	// Recur for all the vertices adjacent to this vertex 
	list<int>::iterator i; 
	for (i = adj[v].begin(); i != adj[v].end(); ++i) 
		if (!visited[*i]) 
			DFSUtil(*i, visited, part, cnct); 
}

int main(){
	int n, m;
	cin >> n >> m;

	int a[n];
	for(int i=0; i<n; i++)
		cin >> a[i];

	Graph g(n);
	g.addFriends(a);

	int t1, t2;
	for(int i=0; i<m; i++){
		cin >> t1 >> t2;
		t1--;	t2--;
		g.addEdge(t1, t2);
	}
	g.printSCCs();
}