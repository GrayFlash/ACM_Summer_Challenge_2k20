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
int n,m,ans=0;
vector<pp> price;
bool com(pp x,pp y){
	return x.ff<y.ff;
} 
int solve(int n,int w,vector<vector<pp>> &p){
    int ans=0;
    for(int k=0;k<n;k++){
        int dp[1003][1003];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=w;j++){
                if(i==0||j==0)
                dp[i][j]=0;
                else{
                    if(p[k][i-1].ff>j){
                        dp[i][j]=dp[i-1][j];
                    }
                    else 
                        dp[i][j]=max(dp[i-1][j],p[k][i-1].ss+dp[i-1][j-p[k][i-1].ff]);
                }
                //cout<<dp[i][j]<<endl;
            }
        }
        ans=max(ans,dp[n][w]); 
    }
    return ans;
}
int main(){
	cin>>n>>m; 
	int x,y;
	string s;
	char c;
	for(int i=0;i<n;i++){
		cin>>s>>c;
		cin>>x>>y;
		if(c=='S'){
			price.pb({x,y});
		}
	} 
	sort(price.begin(),price.end(),com);
	vector<vector<pp>> p(n+1);
    for(int i=0;i<(int)price.size();i++){
        for(int j=0;j<(int)price.size();j++){
            if(i==j) continue;
            p[i].pb(price[j]);
        }
        p[i].pb({price[i].ff/2,price[i].ss});
    } 
	x=solve(price.size(),m,p);
	cout<<x;
}