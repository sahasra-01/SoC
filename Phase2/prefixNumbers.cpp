#include <bits/stdc++.h> 
using namespace std; 

void solve(){
    long long unsigned int x, y, z;
    cin >> x >> y;
	z = x;
    long long unsigned int i = 1;
    while(z <= 1e18){
        z = x*i;
        if(z%y == 0) break; 
        long long unsigned int value_add = y-(z%y);
        if(value_add < i){
            z += value_add;
            break;
        }
        
        i *= 10;
    }
    if(z <= 1e18)
    	cout << z << '\n';
    else 
    	cout << -1 << '\n';
    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;
    while(T--)
        solve();
}



/*
#include <bits/stdc++.h>
using namespace std;

int solve(){
	long long unsigned int x, y, z;
	cin >> x >> y;
	z=x;
	long long unsigned int i=1;
	if(x==0)
		return y;

	while(z <= 1e18){
		z = x*i;
		
		if(z%y==0)
			return z;

		long long unsigned int temp = y-(z%y);
		if(temp < i){
			return z+temp;
		}
		i*=10;
	}
	return z;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while(T--){
		long long unsigned int x = solve();
		if(x <= 1e18)
			cout << x << '\n';
		else
			cout << "-1\n";
	}
}

*/