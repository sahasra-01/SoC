// https://wnccsoc.slack.com/files/U010HBPDA0G/F010T0DB82E/prob-l8b-b.pdf.pdf
#include <bits/stdc++.h>
using namespace std;

struct prof{
	int day, n_lec, curse;
};

bool decreasing(prof a, prof b){
	if(a.curse == b.curse
)		return a.day > b.day;

	return a.curse > b.curse;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, D;
	cin >> N >> D;
	int total_s=0;

	prof d[N];

	int t1, t2, t3;
	for(int i=0; i<N; i++){
		cin >> t1 >> t2 >> t3;
		total_s += t3*t2;			//total curse, finally we'll subtract the ones for which lecture is assigned

		d[i].curse = t3;
		d[i].day = t1;
		d[i].n_lec = t2;	
	}

	sort(d, d+N, decreasing);	//sorted in decreasing order of curse

	bool done[D];
	for(int i=0; i<D; i++)
		done[i] = false;		//initialised all days to be free

	for(int i=0; i<N; i++){										//iterating over every prof
		for(int j=d[i].day-1; j<d[i].day+d[i].n_lec-1; j++){
			if(j >= D)			//extreme case i.e. when prof can teach but holiday is declared
				break;
			if(done[j] == false){	//If no lecture that day, assgin one
				total_s -= d[i].curse;
				done[j] = true;
			}
		}
	}

	cout << total_s << '\n';

}