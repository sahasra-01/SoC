#include <bits/stdc++.h>
using namespace std;

int area(vector <int> &a){
	stack <int> s;
	int n = a.size();
	int ar=0;

	if(n==0)
		return 0;

	s.push(0);

	int i=1;
	while(i < n){
		if(a[i] >= a[ s.top() ]){
			s.push(i);
		}else{
		 	while(!s.empty()){
		 		if(a[s.top()] <= a[i])
		 			break;

		 		int temp = s.top();
				int ar_temp;
		 		s.pop();

		 		if(s.empty()){
		 			ar_temp = a[temp]*i;
		 		}else{
		 			ar_temp = a[temp]*(i-temp);
		 		}
		 		// cout << temp<< " " << i << " "<< ar_temp << "    7\n";
		 		if(ar_temp > ar)
		 			ar = ar_temp;
				
	 		}
	 		s.push(i);
	 	}
	 	i++;
	}

	while(!s.empty()){
 		int temp = s.top();
 		s.pop();
		int ar_temp;

 		if(s.empty()){
 			ar_temp = a[temp]*i;
 		}else{
 			ar_temp = a[temp]*(i-temp);
 		}
		// cout << temp<<" "<< ar_temp << '\n';

 		if(ar_temp > ar)
 			ar = ar_temp;
	}

	return ar;
}

int solve(){
	int n;
	cin >> n;

	vector<int> temp(n,0);
	for(int i=0; i<n; i++){
		cin >> temp[i];
	}

	return area(temp);
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