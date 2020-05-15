#include <bits/stdc++.h>
using namespace std;

bool isPalin(string &s){
	int a=0, b=s.length()-1;

	while(a<b){
		if(s[a] != s[b])
			return false;
		a++;	b--;
	}
	return true;
}

int solve(){
	string s;
	cin >> s;
	int n = s.length();

	if(!isPalin(s)){
		int a=0, b=n-1;
		bool done=false;

		// For cases like asdfda
		while(a<b){
			if(s[a] != s[b]){
				string temp = s;
				temp.erase(a, 1);
				if(isPalin(temp)){
					int cnt=0;

					for(int j=a; j>=0; j--){
						if(s[j] == s[a]){
							cnt++;
						}else
							break;
					}
					return cnt;
				}

				temp = s;
				temp.erase(b, 1);
				if(isPalin(temp)){
					int cnt=0;

					for(int j=b; j<n; j++){
						if(s[j] == s[b])
							cnt++;
						else
							break;
					}
					return cnt;
				}
				
				return 0;
			}
			a++;	b--;
		}

		return 0;
	}
	
	// cases like aca, acca
	if(n%2){
		int mid = n/2;
		int i=0, cnt=0;

		while(i<=mid){
			if(s[mid+i] != s[mid-i] || s[mid+i] != s[mid])
				break;
			i++;
			cnt+=2;
		}

		return cnt;
	}else{
		int mid = n/2;
		int i=0, cnt=0;

		while(i<mid){
			if(s[mid+i] != s[mid-i-1] || s[mid+i]!=s[mid])
				break;
			i++;
			cnt+=2;
		}

		return cnt+1;
	}
	return 0;
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