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
#define ll unsigned long long int
#define mod 1000000009
int main(){
	int t; 
	cin>>t; 
    //string ar="aeiouAEIOU";
	while(t--){
		ll n;
        cin>>n;
        string s;
        cin>>s; 
        ll ans=0;
        for(ll i=0;i<n;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='o'||s[i]=='u'||s[i]=='i'||s[i]=='A'||s[i]=='E'||s[i]=='O'||s[i]=='U'||s[i]=='I'){
                ans+=(n-i)*(i+1);
            }
        }
        cout<<ans<<endl;
	}
}