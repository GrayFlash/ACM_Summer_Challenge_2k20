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
int main(){
	int t; 
	cin>>t;
	while(t--){
		int n,ans=0;
		cin>>n;
		vector<vector<int>> mp(108);
		int a[n],b[n];
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++) cin>>b[i];
		for(int i=0;i<n;i++){
			mp[a[i]].pb(i);
		}
		int j=mp[b[0]][0];
		ans=1;
		for(int i=1;i<n;i++){
			if(mp[b[i]].size()==0){
				ans=-10099;
				break;
			}
			if(mp[b[i]].back()<=j){
				ans++;
				j=mp[b[i]][0];
			}
			else{
				j=*lb(mp[b[i]].begin(),mp[b[i]].end(),j+1);
			}
			//cout<<j<<endl;
		}
		cout<<ans<<"\n";
	}
}