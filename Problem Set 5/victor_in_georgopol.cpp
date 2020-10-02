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
	int t;
	cin>>t;
	while(t--){
		int n,k,flag=1;
		cin>>n>>k;
		vector<int> b;
		vector<int> frq(100009,0);
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
			b.pb(a[i]);
			frq[a[i]]=i;
		}
		sort(b.begin(),b.end());
		for(int i=0;i<n&&k>0;i++){
			if(a[i]==b[i]) continue;
			else{ 
				for(int j=frq[b[i]];j>i&&k>0;j--){
					int temp=a[j];
					frq[a[j]]=j-1;
					frq[a[j-1]]=j;
					a[j]=a[j-1];
					a[j-1]=temp;
					k--;
				}
			}
		}
		for(int i=0;i<n;i++){
			if(a[i]!=b[i]){
				//cout<<a[i]<<"\n";
				flag=0;
				break;
			} 
		}
		if(flag) puts("YES");
		else puts("NO");
	}
}