#include <bits/stdc++.h>
using namespace std;

void idxSortArr(int arr[], int srtd_idx[], int n){//index sort for array
    vector<pair<int, int> > vp;
    for (int i = 0; i < n; ++i) {
        vp.push_back(make_pair(arr[i], i));
    }

    sort(vp.begin(), vp.end());//can also use self-implemented merge sort

    for (int i = 0; i < vp.size(); i++) {
        srtd_idx[i] = vp[i].second;
    }
    return;
}

int main()
{
    int T=1;
    //cin>>T;//add for generalising
    int n=100000, red, curr, ctr[T];

    for(int t=0; t<T; t++){
        //cin>>n;//add for generalising
        int A[n];
        for(int i=0; i<n; i++){
            A[i]=(i+1)*10000;//for given testcase remove o.w.
            //cin>>A[i];//add for generalising
        }
        int srtd_idx[n];
        idxSortArr(A,srtd_idx,n);
        int max_pow = A[srtd_idx[n-1]];
        red=0;
        curr=0;
        ctr[t]=0;
        while(max_pow>=0 && curr<n){
            if(A[srtd_idx[curr]]-red>=0){
                max_pow = max_pow - ( ( (A[srtd_idx[curr]]-red)/(srtd_idx[curr]+1) )+1 )*(srtd_idx[curr]+1);
                ctr[t] = ctr[t] + ( ( (A[srtd_idx[curr]]-red)/(srtd_idx[curr]+1) )+1 );
                red = red + ( ( (A[srtd_idx[curr]]-red)/(srtd_idx[curr]+1) )+1 )*(srtd_idx[curr]+1);
            }
            curr++;
        }
    }
    for(int t=0; t<T; t++){
        cout<<ctr[t]<<endl;
    }

    return 0;
}
