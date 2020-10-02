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
	int n,ans=0;
	cin>>n;
	ll a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	ll sum=0;
	for(int i=0;i<n;i++){
		if(sum<=a[i]){
			ans++;
			sum+=a[i]; 
		}
	}
	cout<<ans;
}