#include <bits/stdc++.h>
using namespace std;

long long int largestRectangleArea(vector<long long int>& a) {
    stack <long long int> s;
    long long int n = a.size();
    long long int ar=0;

    if(n==0)
        return 0;

    s.push(0);

    long long int i=1;
    while(i < n){
        if(a[i] >= a[ s.top() ]){
            s.push(i);
        }else{
            while(!s.empty()){
                if(a[s.top()] <= a[i])
                    break;

                long long int temp = s.top();
                long long int ar_temp;
                s.pop();

                if(s.empty()){
                    ar_temp = a[temp]*i;
                }else{
                    ar_temp = a[temp]*(i-s.top()-1);
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
        long long int temp = s.top();
        s.pop();
        long long int ar_temp;

        if(s.empty()){
            ar_temp = a[temp]*i;
        }else{
            ar_temp = a[temp]*(i-s.top()-1);
        }
        // cout << temp<<" "<< ar_temp << '\n';

        if(ar_temp > ar)
            ar = ar_temp;
    }

    return ar;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(true){
		long long int n;
		cin >> n;
		if(n == 0)
			break;

		vector<long long int> temp(n,0);
		for(long long int i=0; i<n; i++){
			cin >> temp[i];
		}

		cout << largestRectangleArea(temp) << endl;
	}
}