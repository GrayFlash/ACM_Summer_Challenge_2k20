/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000009
typedef pair<int,int> pp;
#define ff first 
#define ss second 
#define pb push_back
#define lb lower_bound 
#define ub upper_bound  
int n,m;
vector<vector<int>> g(1003,vector<int> (1003));
vector<vector<int>> dp(1003,vector<int> (1003,0));
bool valid(int x,int y){
	if(x<1||x>n||y<1||y>m) return false;
	return true;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin>>g[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(g[i][j]==0) dp[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(dp[i][j]){
				dp[i][j]+=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) ans=max(ans,dp[i][j]);
	cout<<ans;
}