#include<bits/stdc++.h>
#include <map> 
#include <vector>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
int main()
{
fast;

int N, Q;
cin>>N>>Q;
vector <int> A[N+7];
for(int i=0; i<N; i++){
    int x_temp;
    cin>>x_temp;
    A[x_temp].push_back(i);
}
for(int i=0; i<Q; i++){
    int D, K, L, R;
    cin>>D>>K>>L>>R;
    L--;
    R--;
    int l = A[D].size();
    if(A[D][0]>R || A[D][l-1]<L){
        cout<<-1<<"\n";
        continue;
    }    
    int k =1;
    for(k=0; k<l; k++){
        if(A[D][k]>=L){
            break;
        }
    }
    int pos_find = k+K-1;
    

    if(pos_find<l && A[D][pos_find]<=R){
        int ans = A[D][pos_find];
        ans+=1;
        cout<<ans<<"\n";
    }

    else cout<<-1<<"\n";
    
}
}