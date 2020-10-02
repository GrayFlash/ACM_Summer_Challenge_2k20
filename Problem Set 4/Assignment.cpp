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
#define ll int
#define mod 1000000009
typedef pair<int,int> pp;
#define ff first 
#define ss second 
#define pb push_back
#define lb lower_bound 
#define ub upper_bound 
int main(){
	ll n,m;
	cin>>n>>m; 
	ll a[n]; 
	vector<ll> c;
	for(int i=0;i<n;i++) cin>>a[i]; 
	sort(a,a+n);
	ll l=0,r=1e7+9;
		while(l<=r){
			ll mid=l+(r-l)/2,x=0;
			int i=0;
			while(i<n){
				x+=(mid/a[i]);
				i++;
			}
			if(x>=m){
				c.pb(mid);
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
	ll mn=1e7;
	for(unsigned int i=0;i<c.size();i++){
		mn=min(c[i],mn);
	}
	cout<<mn;
}