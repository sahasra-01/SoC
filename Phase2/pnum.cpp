#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	unsigned long long int num=1;
	for(int i=0;i<18;i++){num*=10;}
	//cout<<num<<endl;
	while(t--){
		unsigned long long int x,y;
		cin>>x>>y;
		unsigned long long int k=1;
		
		unsigned long long int ans=0;
		while(1){
			if(k*x >num){break;}
			else{
				unsigned long long int p=y-((k*x)%y);
				p%=y;
				if(p<k){
					ans=k*x+p;
					break;}
				else{k*=10;}
				
				}
			}
		if(ans>num || ans==0) {cout<<-1<<endl;}
		else{cout<<ans<<endl;}
		
	
	
			
		}
		
}
