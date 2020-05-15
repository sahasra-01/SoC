#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin >> s;

	int a=0, b=0;
	bool white=false;

	for(int i=0; i<s.length(); i++){
		if(s[i] == 'B'){
			if(white)	b++;
			else		a++;
		}else{
			white = true;
		}	
	}

	if(int(a^b) == 0)
		cout << "Chef\n";
	else
		cout << "Aleksa\n";
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while(T--){
		solve();
	}
}