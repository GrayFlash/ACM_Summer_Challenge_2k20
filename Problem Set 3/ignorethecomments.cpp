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
typedef pair<int,int> pp;
#define ff first 
#define ss second
#define pb push_back 
#define mod 1000000009
int main(){
	int q;
	cin>>q; 
	while(q--){
		string s;
		cin>>s;
		int n=s.length();
		vector<pp > ans;
		int l,r;
		for(int i=0;i<n;i++){
			if(s[i]=='/'&&s[i+1]=='/'){
				i+=2;
				while(s[i]!='/'&&i<n) i++;
                i-=1;
			}
			else if(s[i]=='/'&&s[i+1]!='/'){
				i+=1;
				l=i;
				while(s[i]!='/'&&i<n) i++;
				if(s[i]=='/'&&s[i+1]!='/'){
                    r=i;
                    //i-=1;
				    ans.pb({l,r-l});
                }
                   i-=1;
			}
		}
		cout<<ans.size()<<"\n";
		for(int i=0;i<ans.size();i++) cout<<s.substr(ans[i].ff,ans[i].ss)<<"\n";
	}
}