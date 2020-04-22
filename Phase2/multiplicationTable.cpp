#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int cnt(int x, int i, int m){
	return min((x-1)/i, m);
}

int check(int n, int x, int m){
	int sum=0;
	for(int i=1; i<=n; i++){
		sum += cnt(x, i, m);
	}
	return sum;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	int i=0, j=m-1;

	int ans=0;
	while(i<n && j>=0){
		int temp = check(n, (i+1)*(j+1), m);
		if(temp > k){
			j--;
		}else{
			if(temp > ans)
				ans = temp;
			i++;
		}
	}

	cout << ans << '\n';
}