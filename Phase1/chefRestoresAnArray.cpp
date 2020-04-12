#include <bits/stdc++.h>
#define p 1000000007
using namespace std;

struct interval{
	int s, e;
};

bool incint(interval &a, interval &b){
	return a.s<b.s;
}

int solve(){
	int n, m, k;
	cin >> n >> m >> k;

	int a[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
	}

	vector <interval> inct;
	vector <interval> dect;

	char c;
	interval temp;
	for(int i=0; i<m; i++){
		cin >> c >> temp.s >> temp.e;
		if(c =='I')			inct.push_back(temp);
		else if(c =='D')	dect.push_back(temp);
	}

	sort(inct.begin(), inct.begin(), incint);
	sort(dect.begin(), dect.begin(), incint);

	vector <interval> inc;
	vector <interval> dec;

	for(int i=1; i<inct.size(); i++){
		if(inct[i].s <= inct[i-1].e){
			temp.s = inct[i-1].s;
			temp.e = inct[i].e;
			inc.push_back(temp);
		}else{
			if(i == 1)
				inc.push_back(inct[0]);
			inc.push_back(inct[i]);
		}
	}

	for(int i=1; i<dect.size(); i++){
		if(dect[i].s <= dect[i-1].e){
			temp.s = dect[i-1].s;
			temp.e = dect[i].e;
			dec.push_back(temp);
		}else{
			if(i == 1)
				dec.push_back(dect[0]);
			dec.push_back(dect[i]);
		}
	}

	vector <int> dx(n, 0);

	for(int i=0; i<inc.size(); i++){
		for(int j=inc[i].s; j<=inc[i].e; j++){
			if(dx[j]==0)
				dx[j] = 1;
			else
				return 0;
		}
	}
	for(int i=0; i<dec.size(); i++){
		for(int j=dec[i].s; j<=dec[i].e; j++){
			if(dx[j]==0)
				dx[j] = -1;
			else
				return 0;
		}
	}

	long int ans=1;
	int contin=0, contde=0;
	int max=0, min=0;

	int i=0;
	while(true){
		if(dx[i]==0){
			j=i;
			if(i != 0)
				j++;
			while(dx[j]==0){
				if(a[j] == -1){
					ans *= k;
					ans %= p;
				}
			}
		}
	}


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