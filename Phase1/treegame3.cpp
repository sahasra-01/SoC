#include <bits/stdc++.h>
using namespace std;

class Tree{
	int n;
	vector<vector<int>> *child;
	int *depth;
	int max_dep;
public:
	Tree(int x){
		n = x;
		child = new vector<vector<int>> (n);
		depth = new int[n];
		depth[0]=0;
	}

	void create(int i, int a){
		child[i].push_back(a);
	}

	void assign_dep(int t){
		for(int i=0; i<child[t].size(); i++){
			depth[child[t][i]] = 1 + depth[t];
			assign_dep(i);
		}
		return;
	}

	void depmax(){
		int temp = 0;
		for(int i=0; i<n; i++){
			if(depth[i] > temp)
				temp = depth[i];
		}
		max_dep = temp;
		return;
	}

	int ans(){
		int ans = 0;
		int curr_dep=0;
		
		for(int i=0; i<max_dep+1; i++){
			if(i%2 == 0){
				curr_dep++;
				ans++;
				if(max_dep == curr_dep){
					if(depth[max_dep] == 1)
						return ans+1;
					else
						return ans+2;
				}
			}else{
				depth[max_dep]--;
				if(depth[max_dep] == 0)	max_dep--;
				ans++;
				if(max_dep == curr_dep)
					return ans+1;
			}

		}
		return ans;
	}
};

int solve(){
	int num;
	cin >> num;

	cout << "FO1\n";
	Tree t(num);

	int a, b;
	for(int i=0; i<num-1; i++){
		cin >> a >> b;
		a--;	b--;
		t.create(a, b);
	}

	t.assign_dep(0);
	t.depmax();

	return t.ans();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	cout << " FO2\n";
	while(T--){
		cout << solve() << '\n';
	}
}