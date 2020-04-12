#include <bits/stdc++.h>
using namespace std;

long int area(vector <int> &heights){
	stack <pair<int,int>> rect;
	stack <pair<int,int>> revrect;
	int n = heights.size();
	vector <pair<int,int>> spread(n);
	if(n == 0)
		return 0;
	if(n == 1)
		return heights[0];

	rect.push( {heights[0], 0} );
	for(int i=1; i<n; i++){
		int cnt=0;

		if(i == n-1){
			while(!rect.empty()){
				spread[ rect.top().second ].second = i-rect.top().second;
				rect.pop();		
			}
			spread[ i ].second = 0;
			break;
		}

		// possible error here
		if(!rect.empty()){
			while(heights[i] < rect.top().first){
				spread[ rect.top().second ].second = i-rect.top().second-1;
				rect.pop();
				if(rect.empty())
					break;
			}
		}
		if(heights[i]!=heights[i-1])
			rect.push( {heights[i], i} );
	}

	revrect.push( {heights[n-1], n-1} );
	for(int i=n-2; i>=0; i--){
		int cnt=0;
		
		if(i == 0){
			while(!revrect.empty()){
				if(revrect.top().first <= heights[i] )
					spread[ revrect.top().second ].first = revrect.top().second-i;
				
				revrect.pop();		
			}
			spread[ i ].first = 0;
			break;
		}

		// possible error here
		if(!revrect.empty()){
			while(heights[i] < revrect.top().first){
				spread[ revrect.top().second ].first = revrect.top().second-i-1;
				revrect.pop();
				if(revrect.empty())
					break;
			}
		}

		if(heights[i] != heights[i+1])
			revrect.push( {heights[i], i} );
	}

	for(int i=0; i<n; i++){
		cout << spread[i].first << " " << spread[i].second << '\n'; 
	}

	long int maxim=0;
	for(int i=0; i<n; i++){
		int t_area = heights[i]*(1+spread[i].first+spread[i].second);
		if(t_area > maxim){
			maxim = t_area;
		}
	}

	return maxim;
}

long int solve(){
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