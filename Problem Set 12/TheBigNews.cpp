#include<bits/stdc++.h>
#include<vector>
#include <queue>
#define intt long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define pb push_back
vector<int>q[1000000 + 7];
vector<int>brr,arr(1000000 +7,0);
vector<int>root[1000000 + 7];

void dfs(int T,int &a,vector<bool>&visited){
	visited[T]=1;

	for(auto itr:root[T]){
		for(auto itr1:q[itr])
		{
			if(visited[itr1]==0){
				a++;
				brr.pb(itr1);
				dfs(itr1,a,visited);
			}
		}
	}
}

int main(){ 
	fast;
	int N;
	cin>>N;
	int M;
	cin>>M;
	for(int i=1;i<=M;++i)
	{
		int k;
		cin>>k;
		for(int j=0;j<k;++j)
		{
			int Temp;
			cin>>Temp;
			root[Temp].pb(i);
			q[i].pb(Temp);
		}
	}
	for(int i=1;i<=N;++i)
	{
		int a=1;
		vector<bool>visited(N+1,0);
		if(arr[i]==0)
		{
			brr.clear();
			dfs(i,a,visited);
			for(int i=0;i<brr.size();++i)
				arr[brr[i]]=a;
			arr[i]=a;
		}
		cout<<arr[i]<<" ";
	}
}