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
unordered_map <ll,ll>mp2; 
vector<ll> mp;
void solve(){
	mp.pb(0);
    mp.pb(1);
    mp.pb(1);
	for(int i=3,x=0;i<60&&x<=1e6+9;i++){
		x=mp[i-1]+mp[i-2];
        mp.pb(x);
		mp2[mp[i]]=1;
	}
}
int main(){
	int t; 
	cin>>t; 
	solve();
	while(t--){
		int n; 
		cin>>n; 
		int ans=0; 
		for(int i=mp.size()-1;i>=0&&n>0;i--){
            if(mp[i]>n) continue;
            else{
                n-=mp[i];
                ans++; 
                //if(mp2[n]) n=0,ans++;
            }
        }
		cout<<ans<<"\n";
	}
}