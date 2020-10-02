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
	int n; 
	cin>>n; 
	int a[n],b[n]; 
	queue <int> q; 
	vector<bool> v(n+1,0);
	for(int i=0,x;i<n;i++){
		 cin>>x;
		 q.push(x);
	}
	for(int i=0,x;i<n;i++){
		 cin>>b[i];
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if(q.front()==b[i]){ 
			v[b[i]]=1;
			while(!q.empty()&&v[q.front()]) q.pop();
		}
		else{
			if(v[b[i]]) continue;
			v[b[i]]=1;
			ans++;
		}
	}
	cout<<ans;
}