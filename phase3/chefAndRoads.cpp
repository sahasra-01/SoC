#include<bits/stdc++.h> 
#define ll long long int
#define MOD 1000000007
using namespace std; 
  
class Graph 
{ 
    ll V;
    list<ll> *adj; 
    vector <ll> sorted;
    ll *dp;
    void topologicalSortUtil(ll v, bool visited[], stack<ll> &Stack); 
public: 
    Graph(ll V);   // Constructor 
    void addEdge(ll v, ll w); 
    void topologicalSort();
    void prlladj();
    ll ways(ll a, ll b);
}; 
  
Graph::Graph(ll V) 
{ 
    this->V = V; 
    adj = new list<ll>[V]; 
    dp = new ll[V];
} 
  
void Graph::addEdge(ll v, ll w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
} 
  
// A recursive function used by topologicalSort 
void Graph::topologicalSortUtil(ll v, bool visited[],  
                                stack<ll> &Stack) 
{ 
    // Mark the current node as visited. 
    visited[v] = true; 
  
    // Recur for all the vertices adjacent to this vertex 
    list<ll>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
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

ll Graph::ways(ll a, ll b){
    ll bi;
    for(ll i=sorted.size()-1; i>=0; i--){
        if(sorted[i] == b){
            dp[sorted[i]] = 1;
            bi = i;
            break;
        }
        dp[sorted[i]] = 0;
    }

    for(ll i=bi-1; i>=0; i--){
        dp[sorted[i]] = 0;
        for(auto it = adj[sorted[i]].begin(); it!=adj[sorted[i]].end(); it++){    
            // cout << "   " << sorted[i] << " " << *it << '\n';            
            dp[sorted[i]] = (dp[sorted[i]] + (dp[*it])%MOD)%MOD;
        }
        // cout << " " << sorted[i] << " " << dp[sorted[i]] << '\n';
        if(sorted[i] == a)
            return dp[a]%MOD;
    }
    return 0;
}

void Graph::prlladj(){
    for (ll i=0; i<V; i++){
        for (auto it=adj[i].begin(); it!=adj[i].end(); it++)
            cout <<"friend" <<  i << " " << *it << '\n';
    }
}


// Driver program to test above functions 
int main() 
{ 
    // Create a graph given in the above diagram 
    ll n, m;
    cin >> n >> m;
    ll p, q;
    cin >> p >> q;
    p--;    q--;

    Graph g(n);

    ll a, b;
    for(ll i=0; i<m; i++){
        cin >> a >> b;
        a--;    b--;
        g.addEdge(a, b);
    } 

    // g.prlladj();

    g.topologicalSort(); 
    
    cout << g.ways(p, q) << '\n';
    return 0; 
} 
