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
		int n;
		cin>>n;
		vector<string> str(n);
		vector<bitset<27>> v(n);
		for(int i=0;i<n;i++){
			cin>>str[i];
			int l=str[i].length();
			for(int j=0;j<l;j++){
				v[i][str[i][j]-'a']=1;
			}		
		}
		int ans=0;
		for(int i=0;i<n;i++){
			int l1=str[i].length();
			for(int j=i+1;j<n;j++){
				bitset<27> x=v[i]&v[j];
				if(!(x.count())){
					int l2=str[j].length();
					ans=max(ans,l1*l2);
				}
			}
		}
		cout<<ans<<"\n";
	}
}