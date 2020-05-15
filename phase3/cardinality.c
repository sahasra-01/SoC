#include<stdio.h>

typedef long long ll;
int i,m;
#define FOR(i,n) for(i=0;i<(n);i++)

ll A[128];
ll S[1024], C[1024];

void adjust(int idx, int su, int ca) {
	if (S[idx] < su) {
		S[idx] = su;
		C[idx] = ca;
	} else if (S[idx] == su && C[idx] < ca) {
		C[idx] = ca;
	}
}

int bitset(int A){
    int bit = 0, t = A;
        while(t) {
            bit |= (1<<(t%10));
            t /= 10;
        }
    return bit;
}

int main() {
	int N;
	int te = 0;
	while(scanf("%d",&N)!=EOF) {
		FOR(i,N) {
			scanf("%ld",&A[i]);
		}
		FOR(i,1024) {
			S[i] = 0;
			C[i] = 0;
		}
		FOR(i,N) {
			int bit=bitset(A[i]);
			adjust(bit,A[i],1);
		}
		FOR(i,N){
		    int bit=bitset(A[i]);
            FOR(m,1024){
                if((m & bit)==0)
                    adjust(m+bit,S[m]+S[bit],C[bit]+C[m]);
            }
		}
		int mas = 0, mac = 0;
		FOR(i,1024) {
			if (S[i] > mas) {
				mas = S[i];
				mac = C[i];
			} else if (S[i] == mas && C[i] > mac) {
				mac = C[i];
			}
		}
		printf("%d\n",mac);
		te+=1;
	}
	return 0;
}
