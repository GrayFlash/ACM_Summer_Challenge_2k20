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
#define ll long
#define mod 1000000007
#define pb push_back
#define ff first 
#define ss second  
typedef pair<ll,ll> pp;
bool com(pp x,pp y){
    return x.ff<y.ff;
} 
int main(){
	int t;
	cin>>t; 
	int n,m;
	ll sum=0,k;
	while(t--){
		cin>>n>>m;
		sum=0;
		int a[n+2][m+2]={};
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
				sum+=a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				k=0;
				if(a[i][j]<a[i-1][j]) k=a[i][j];
				if(a[i][j]<a[i][j-1]) k=a[i][j];
				if(a[i][j]<a[i+1][j]) k=a[i][j];
				if(a[i][j]<a[i][j+1]) k=a[i][j];
				if(a[i][j]<a[i-1][j-1]) k=a[i][j];
				if(a[i][j]<a[i+1][j+1]) k=a[i][j];
				if(a[i][j]<a[i+1][j-1]) k=a[i][j];
				if(a[i][j]<a[i-1][j+1]) k=a[i][j];
				sum-=k;
			}
		}
		cout<<sum<<endl;
	}
}