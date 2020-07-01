#include<bits/stdc++.h>
#include <queue> 
#define intt long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main()
{
fast;
intt T,ans=0;
int x;
cin>>T;
int N;
while(T--)
{
    cin>>N;
    priority_queue <int> q;
    for(int i=0; i<N; i++){
        cin>>x;
        q.push(x);
    }
    int flag = 2;
    for(int i=0; i<N; i++){
        x = q.top();
        q.pop();
        if(q.empty()){
            flag = 2;
            break;
        }
        int y = q.top();
        q.pop();
        x = x-y;
        if(x!=0) q.push(x);
        if(q.empty()){
            flag = 1;
            break;
        }
    }
    if(flag==1){
        cout<<-1<<"\n";
    }
    else{
        cout<<x<<"\n";
    }
}
    
}