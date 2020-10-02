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
long int ans=0;
void merge(vector<int> &a,int l,int mid,int r){
	vector<int> b(r-l+1,0);
	int p=l,q=mid+1,k=0;
	for(int i=l;i<=r;i++){
		if(p>mid){
			b[k]=a[q];
			k++;
			q++;
		}
		else if(q>r){
			b[k]=a[p];
			p++;
			k++;
		}
		else if(a[q]>=a[p]){
			b[k]=a[p];
			k++;
			p++;
		}
		else{
			b[k]=a[q];
			q++;
			k++;
			ans+=(mid-p+1);
		}
	}
	for(int i=0;i<k;i++) a[i+l]=b[i];
}
void solve(vector<int> &a,int l,int r){
	if(l>=r) return;
	int mid=l+(r-l)/2;
	solve(a,l,mid);
	solve(a,mid+1,r);
	merge(a,l,mid,r);
}
int main(){ 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t; 
	cin>>t; 
	while(t--){
		ans=0;
		int n;
		cin>>n; 
		vector<int> a(n);
		for(int i=0;i<n;i++) cin>>a[i];
		solve(a,0,n-1);
		cout<<ans<<"\n";
	}
}