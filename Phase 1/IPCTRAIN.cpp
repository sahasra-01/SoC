/* 
https://wnccsoc.slack.com/files/U010HBPDA0G/F010T0DB82E/prob-l8b-b.pdf.pdf

https://www.codechef.com/problems/IPCTRAIN
*/

#include <bits/stdc++.h>
using namespace std;

struct prof{
	long int day, n_lec, curse;
};

bool whoCameFirst(prof &a, prof &b){
	return a.day<b.day;
}

long int solve(){
	long int N, D;
	cin >> N >> D;

	prof p[N];
	long int T_curse=0;

	long int t1, t2, t3;
	for(long int i=0; i<N; i++){
		cin >> t1 >> t2 >> t3;
		p[i].day = t1;
		p[i].n_lec = t2;
		p[i].curse = t3;
		T_curse += t3*t2;
	}

	// Sorted according to which prof came first
	sort(p, p+N, whoCameFirst);

	// Priority queue sorted according to the prof with highest curse (available) on top
	priority_queue < tuple<long int,long int,long int> > q;

	// Since modifing value of an element in prio. queue is not possible,
	// this array is used to do the same, key to which is stored in the priority queue
	long int noOfLec[N];
	
	long int ip = 0, t = 0;
	for(long int i=1; i<=D; i++){
		/* Prof who came on that day is inserted in the queue */
		if(p[ip].day == i){
			q.push( {p[ip].curse, p[ip].day, t} );
			noOfLec[t] = p[ip].n_lec;
			t++;	ip++;		//Counters for key to noOfLec and prof respectively
		}

		/* When there is no prof. to take lecture on that day */
		if(q.size() == 0)
			continue;

		/* Prof with highest curse took a lecture */
		noOfLec[ get<2>(q.top()) ]--;
		T_curse -= get<0>(q.top());

		/* No more lecture required by the prof. */
		if(noOfLec[ get<2>(q.top()) ] == 0){
			q.pop();
		}
	}

	return T_curse;
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