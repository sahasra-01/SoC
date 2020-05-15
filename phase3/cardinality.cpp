#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll bset(ll a){
	ll ans=0;

	while(a > 0){
		ans |= (1<<(a%10));
		a /= 10;
	}

	cout << ans << " ye lo \n";

	return ans;
}

ll solve(ll *a, ll n){
	pair<ll,ll> sum[2050];
	ll b;
	for(ll i=0; i<2050; i++){
		sum[i].first = 0;
		sum[i].second = 0;
	}

	for(ll i=0; i<n; i++){
		b = bset(a[i]);
		sum[b].first = a[i];
		sum[b].second = 1;
		for(ll m=0; m<=2048; m++){
			if((m&b) == 0){
				// cout << m+b << "  ahfsj\n";
				ll t1 = sum[m+b].first;
				ll t2 = sum[m].first+sum[b].first;
				if(t1<=t2){
					sum[m+b].first = t2;
					sum[m+b].second = sum[m].second + sum[b].second;
				}
			}
		}
	}

	ll max=0, card=0;
	for(ll i=0; i<2050; i++){
		if(max < sum[i].first){
			max = sum[i].first;
		}
	}
	for(ll i=0; i<2050; i++){
		if(sum[i].first == max){
			if(sum[i].second > card){
				card = sum[i].second;
			}
		}
	}

	return card;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	while(cin >> n){
		ll a[n];

		for(ll i=0; i<n; i++){
			cin >> a[i];
		}

		cout << solve(a, n) << endl;
	}
}