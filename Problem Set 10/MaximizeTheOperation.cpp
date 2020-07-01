#include<bits/stdc++.h>
#include <cmath>
#define intt long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main()
{
fast;
intt T,ans=0,x;
cin>>T;
int arr[10000000]; 
int prime[1000000];
prime[0] = 2;
prime[1] = 3;
int pos = 2;
for(int j=5; j<=3000; j++){
    int k=0;
    for(k=0; k<pos; k++){
        if(j%prime[k] == 0) break;
    }
    if(k==pos) {
        prime[pos] = j;
        pos++;
    }
}

while(T-->0){
    int N; 
    cin>>N;
    int count = 0;
    int Num = N;
    for(int i=0; i<pos; i++){
        if(N==1) break;
        if(arr[N] != 0){
            count += arr[N];
            break;
        }
        if(prime[i] > sqrt(N)){
            N = 1;
            count++;
            break;
        }
        while(N%prime[i]==0){
            if(arr[N]!=0){
            count += arr[N];
                N = 1;
                break;
            }
            N = N/prime[i];
            count++;
        }
    }
    arr[Num] = count;
    cout<<count<<"\n";
}
}