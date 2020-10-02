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
		float x,y,a;
		cin>>x>>y>>a;
		if(x*x==4*a*y) cout<<"YES\n";
		else cout<<"NO\n";
	}
}