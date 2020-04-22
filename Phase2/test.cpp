#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a = 10;
	int b = 10;

	set <int> s;

	for(int i=1; i<=a; i++){
		for (int j=1; j<=b; j++)
			cout << i*j << " ";
		cout << '\n'; 
	}
/*
	for(auto it = s.begin(); it!=s.end(); it++){
		cout << *it << " ";
	}*/
}
/*
#include <bits/stdc++.h>
using namespace std;

int main(){
	set	<int> s;
	s.insert(4);
	s.insert(2);
	s.insert(5);
	s.insert(1);
	s.insert(10);

	for(auto it=s.begin(); it!=s.end(); it++)
		cout << *it << " ";
	cout << '\n';

}*/