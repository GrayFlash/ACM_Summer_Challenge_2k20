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
typedef pair<ll,int> pp;
#define ff first 
#define ss second 
#define pb push_back
#define lb lower_bound 
#define ub upper_bound 
int main(){
	int n,m,q,x,y; 
	scanf("%d %d %d",&n,&m,&q);
	ll z;
	//ll a[n][m]={0}; 
	vector<pp > rw(n,{0,0});
	vector<pp > col(m,{0,0});
	int i=1;
	while(i<=q){
		scanf("%d %d %lld",&x,&y,&z);
		if(x==1){
			rw[y-1]={z,i};
		}
		else{
			//for(int i=0;i<n;i++) a[i][y-1]=z;
			col[y-1]={z,i};
		}
		i++;
	} 
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(rw[i].ss>col[j].ss){
				printf("%lld ",rw[i].ff);
			}
			else{
				printf("%lld ",col[j].ff);
			}
		}
		printf("\n");
	}
}