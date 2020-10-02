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
#define mod 1000000007
int main(){
	int n;
	ll k;
	cin>>n>>k; 
	ll ans=0;
	ll a[n],b[n];
	for(int i=0;i<n;i++) cin>>a[i],b[i]=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]) b[i]++;
		}
	}
	ll x=0,y=0,z=0,c,d;
	for(int i=0;i<n;i++){
		x=0;
		for(int j=(i+1)%n;j<n*2;j++){
			if(a[i]>a[j%n]) x++;
			if(i==(j%n)) y=x;
		}
		c=b[i];
		z=(((x-c)*(k-1))+c);
		if(y==0) y=1;
		ans=(ans+((d*((z%mod+c%mod)%mod))/2)%mod)%mod;
        //cout<<ans<<endl;
	}
	cout<<ans%mod<<endl;
}