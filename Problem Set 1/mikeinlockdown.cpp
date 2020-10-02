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
	int t; 
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll ans=0;
		int a[n],b[n],c[n];
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++) cin>>b[i];
		for(int i=0;i<n;i++){
			cin>>c[i];
			if(c[i]<b[i]+a[i]){
				ans+=(b[i]+a[i])-c[i];
			}
		}
		cout<<ans<<endl;
	}
}