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
int main(){
	int n,k; 
	cin>>n>>k;
	ll ans=0;
	ll sum=0;
	vector<ll> pre(n+1,0),a(n+1),pre1(n+1,0);
	vector<int> s(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]) pre[i]=a[i];
		else pre1[i]=a[i];
		pre[i]+=pre[i-1];
		pre1[i]+=pre1[i-1];
	} 
    //cout<<pre[n]<<endl;
	for(int i=1;i<=n-k+1;i++){
		if(s[i]) continue;
		sum=pre[n]+pre1[i+k-1]-pre1[i-1];
		//cout<<sum<<endl;
		ans=max(ans,sum);
	}
	cout<<ans;
}