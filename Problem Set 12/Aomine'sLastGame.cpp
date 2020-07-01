#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N;
vector<int> arr;
void strip(vector<int>* graph,int* curr,int* fin,int a,int b,bool* visited,int node,int curlevel){
	visited[node]=true;
	if(curlevel%2==0 && a%2==1){
		curr[node] = !curr[node];
	}else if(curlevel%2==1 && b%2==1){
		curr[node] = !curr[node];
	}
	if(curr[node]!=fin[node]){
		curr[node]=fin[node];
		arr.push_back(node+1);
		if(curlevel&1)b++;
		else a++;
	}
	for(int i=0;i<graph[node].size();i++){
		int k = graph[node][i];
		if(!visited[k]){
			strip(graph,curr,fin,a,b,visited,k,curlevel+1);
		}
	}
}
 
int main(){
fast;
cin>>N;
vector<int> trees[N];
int A,B;
for(int i=0;i<N-1;i++){
	cin>>A>>B;
	trees[A-1].push_back(B-1);
	trees[B-1].push_back(A-1);
}
int curr[N];int fin[N];
bool visited[N];
memset(visited,0,N*sizeof(bool));
for(int i=0;i<N;i++)cin>>curr[i];
for(int i=0;i<N;i++)cin>>fin[i];
strip(trees,curr,fin,0,0,visited,0,0);
sort(arr.begin(),arr.end());
cout<<arr.size()<<"\n";
for(int i=0;i<arr.size();i++){
	cout<<arr[i]<<"\n";
}
}