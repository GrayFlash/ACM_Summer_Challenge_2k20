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
	int n;
	cin>>n;
	ll x;
    vector<ll> b; 
    map<ll,int> mp;
	vector<ll> div3,div2,div1;
	for(int i=0;i<n;i++){
		cin>>x;
		if(mp[x]) continue;
        b.pb(x);
        mp[x]=1;
		if(x%3==0) div3.pb(x);
		else if(x%2==0) div2.pb(x);
		else div1.pb(x);
	}
	int j=0; 
    //cout<<b.size()<<endl;
	int ans1=0,ans2=0,ans3=0;
	sort(b.begin(),b.end());
	sort(div3.begin(),div3.end());
	sort(div2.begin(),div2.end());
	sort(div1.begin(),div1.end()); 
	for(int i=0;i<div3.size();i++){
		if(div3[i]>b[j]){
			ans1++;
		}
		else if(div3[i]<b[j]) ans2++;
		else ans3++;
        //cout<<b[j]<<" ";
        j++;
	}
	for(int i=0;i<div2.size();i++){
		if(div2[i]>b[j]){
			ans1++;
		}
		else if(div2[i]<b[j]) ans2++;
		else ans3++;
        //cout<<b[j]<<" ";
        j++;
	}
	for(int i=0;i<div1.size();i++){
		if(div1[i]>b[j]){
			ans1++;
		}
		else if(div1[i]<b[j]) ans2++;
		else ans3++;
        //cout<<b[j]<<" ";
        j++;
	} 
    //cout<<endl;
	cout<<ans1<<" "<<ans2<<" "<<ans3;
}