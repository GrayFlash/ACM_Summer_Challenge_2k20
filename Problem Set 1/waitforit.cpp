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
		ll a,b,c,d,ans=0;
		cin>>a>>b>>c>>d;
		if(a>=b){
			ans+=b;
			b=0;
		}
		else{
			ans+=a;
			b-=a;
		}
		if(b<=c&&b<=d) ans+=b;
		else if(b>=c&&d>=c) ans+=c;
		else if(b>=d&&c>=d) ans+=d;
		cout<<ans<<endl;
	}
}