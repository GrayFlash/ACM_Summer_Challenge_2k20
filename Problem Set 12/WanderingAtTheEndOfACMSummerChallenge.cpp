#include<bits/stdc++.h>
#include<vector>
#include<queue>
#include<string> 
#define intt long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main()
{
    fast;
    intt N, M;
    cin>>N>>M;
    vector <int> adj[N+2];
    for(int i=0; i<M; i++){
        int A, B;
        cin>>A;
        cin>>B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    int arr[N+2];
    int visited[N+2];
    priority_queue <int, vector<int>, greater<int>> q; 
    q.push(1);
    for(int i=0; i<N; i++){
        visited[i] = 0;
    }
    visited[1] = 1;
    while(q.size()>0){
        int Temp = q.top();
        cout<<Temp<<" ";
        q.pop();
        visited[Temp] = 1;
        int pos= 0;
        for(int i=0; i<adj[Temp].size(); i++){
            if(visited[adj[Temp][i]]!=1){
                visited[adj[Temp][i]]=1;
                q.push(adj[Temp][i]);
            }
        }
    }
    cout<<"\n";
    
}