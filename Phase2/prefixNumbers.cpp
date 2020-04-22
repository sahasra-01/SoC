#include <bits/stdc++.h>
#include <boost/lexical_cast.hpp>
#define mint 1000000000000000000
using namespace std;

bool pref(string &a, string &b){
	for(int i=0; i<a.length(); i++){
		if(a[i] != b[i])
			return false;
	}
	return true;
}

long long solve(){
	long long x, y;
	cin >> x >> y;

	for(long long z=y; z<=10000000000000; z+=y){
		string a, b;
		ostringstream temp1, temp2;
		temp1 << x;
		temp2 << z;

		a = temp1.str();
		b = temp2.str();

		if(pref(a, b))
			return z;
	}
	return -1;
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