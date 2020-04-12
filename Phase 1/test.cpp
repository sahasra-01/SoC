#include <bits/stdc++.h>
using namespace std;

struct temp{
	int a, b;
};

bool doit(temp a1, temp a2){
	return a1.a<a2.a;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	temp v[5];

	for(int i=0; i<5; i++){
		v[i].a = 10*(5-i)+5;
		v[i].b = 100*(5-i)+5;
	}

	sort(v, v+5, doit);

	for(int i=0; i<5; i++){
		cout << v[i].a << " "<< v[i].b << '\n';
	}
}