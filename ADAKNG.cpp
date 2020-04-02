// https://wnccsoc.slack.com/files/U0104JJVDTL/F0109VBAJ67/screenshot_2020-03-24-11-50-05-832_com.android.chrome.jpg

#include <bits/stdc++.h>
using namespace std;

int solve(){
	int r, c, k;
	cin >> r >> c >> k;

	int a=0, b=0;

	if(k+r <= 8)	a+=k;
	else			a+=8-r;

	if(k+c <= 8)	b+=k;
	else			b+=8-c;

	if(r-k-1 > 0)	a+=k+1;
	else			a+=r;

	if(c-k-1 > 0)	b+=k+1;
	else			b+=c;

	return a*b;
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