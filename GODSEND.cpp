//https://wnccsoc.slack.com/files/U010HBPDA0G/F010MNMMF6K/image_from_ios.png

#include<bits/stdc++.h>
using namespace std;
     
int main(){
	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
    
   	int n;
   	cin >> n;
   	int x, cnt=0;
    
/*
Second Guy can win only if there are only even no(s).   
*/    
   	for(int i=0; i<n; i++){
   		cin >> x;
   		if(x%2)
   			cnt++;
   	}
    
   	if(cnt == 0)
   		cout << "Second\n";
   	else
   		cout << "First\n";
}