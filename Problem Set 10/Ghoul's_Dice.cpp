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
		ll n;
		cin>>n; 
		int sum=27;
		ll ans=(n/sum)*sum;
		if(n<=27){
			ll d=(27-n);
			if(d<2||d>7){
				puts("NO");
				continue;
			}
			else{
				puts("YES");
				continue;
			}
		}
		else{
            bool flag=0;
			for(int i=20;i<=25;i++){ 
                ll x=(long long)(n-i); 
                //cout<<(x%18)<<endl;
                if(x%18==0){
                    flag=1; 
                    break;
                }
            }
            if(flag) puts("YES");
            else puts("NO");
		}
	}
}