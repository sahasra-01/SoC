#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string b;
	cin >> b;

	stack <pair<char,int>> s;

	s.push({b[0],0});

	int i=1;
	while(true){
		if(!s.empty()){
			if(s.top().first == '(' && b[i] == ')'){
				while(s.top().first == '(' && b[i] == ')'){
					s.pop();
					i++;
					if(i >= b.length())
						break;
					if(s.empty())
						break;
				}
			}
		}
		if(i >= b.length())
			break;
		
		s.push({b[i],i});
		i++;
	}

	vector <int> v;
	while(!s.empty()){
		v.push_back(s.top().second);
		s.pop();
	}



	if(v.size() == 0){
		cout << b.length() << " 1\n";
		return 0;
	}

	if(v.size() == b.length()){
		cout << "0 1\n";
		return 0;
	}

	vector <int> ans;

	// cout << b.length() << '\n';

	ans.push_back(b.length()-v[0]-1);

	for(i=1; i<v.size(); i++){
		ans.push_back( v[i-1]-v[i]-1 );
	}

	ans.push_back(v[i-1]);

	int total=0, maxim=0;;

	for(int i=0; i<ans.size(); i++){
		if(ans[i] != 0){
			if(ans[i] > maxim){
				maxim = ans[i];
			}
		}
	}

	for(int i=0; i<ans.size(); i++){
		if(ans[i] == maxim)
			total++;
	}
		/*for(int i=0; i<v.size(); i++){
			cout << v[i] << " ";
		}
		cout << endl;*/

	cout << maxim << " " << total << '\n';
}