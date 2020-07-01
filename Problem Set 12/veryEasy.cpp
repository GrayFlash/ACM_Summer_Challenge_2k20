#include<bits/stdc++.h>
#include<vector>
#define intt long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main()
{
    fast;
    intt N, M;
    cin>>N;
    if(N==1){
        cout<<1<<endl<<1;
    }
    else{
         M = N-1;
        vector <int> adj[N+2];
        for(int i=0; i<M; i++){
            int A, B;
            cin>>A;
            cin>>B;
            adj[A].push_back(B);
            adj[B].push_back(A);
        }
        int colors[N+2];
        colors[1] = 1;
        int visited[N+2];
        queue <int> q; 
        q.push(1);
        for(int i=0; i<N; i++){
            visited[i] = 0;
        }
        visited[1] = 1;
        int count1=1, count2=0;
        colors[0] = 1;
        int pos = 0, max=0;
        while(!q.empty()){
            int Temp = q.front();
            q.pop();
            int color = 1;
            if(colors[Temp] == 1) color = 2;
            int Temp_count=0;
            pos=0;

            for(int i=0; i<adj[Temp].size(); i++){
                if(visited[adj[Temp][i]]!=1){
                    visited[adj[Temp][i]]=1;
                    q.push(adj[Temp][i]);
                    colors[adj[Temp][i]] = color;
                    Temp_count++;
                }
            }
            if(color==1) count1 += Temp_count;
            else count2 += Temp_count;
        }
        cout<<2<<"\n";
        
        cout<<count1<<" "<<count2<<"\n";
    }
   
}