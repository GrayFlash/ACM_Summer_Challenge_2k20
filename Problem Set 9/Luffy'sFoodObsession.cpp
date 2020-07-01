#include<bits/stdc++.h>
#include <map>
using namespace std;
int main(){
    long long T;
    
    cin>>T;
    while(T-->0){
        long long N;
        int M;
        long long A[100000];
        cin>>N>>M;
        for(int i=0; i<M; i++){
            cin>>A[i];
        }
        int arr[64];
        int brr[64];
        for(int i=0;i<64;i++){
            arr[i]=0;
            brr[i]=0;
        }
        int j=0, pos=0;
        while(N>0){
            if(N%2==1)brr[pos]=1;
            pos++;
            N/=2;
        }
        for(int i=0;i<M;i++){
            pos=0;
            while(A[i]>0){
                pos++;
                A[i]/=2;
            }
            arr[pos-1]++;
            
        }
        long long sum=0;
        int flag=0;
        for(int i=0;i<64;i++){
            while(i<64 && brr[i]==0)i++;
            if(i==64)break;
            for(j=0;j<i;j++){
                arr[j+1]+=arr[j]/2;
                arr[j] = arr[j]%2;
            }
            if(arr[i]>0){
                arr[i]-=1;
                brr[i]=0;
            }
            else{
                j=i;
                while(j<64 && arr[j]==0)j++;
                if(j==64){
                    cout<<-1<<"\n";
                    flag=1;
                    break;
                }
                arr[j]-=1;
                for(int k=j-1;k>i;k--){
                    arr[k]=1;
                }
                sum+=(j-i);
            }
        }
        if(flag==0)
        cout<<sum<<"\n";
    } 
    return 0;
}