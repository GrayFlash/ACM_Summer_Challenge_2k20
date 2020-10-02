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
	string s,ans; 
	cin>>s; 
	ans="";
	//p="";
    int n=s.length();
	int frq[27]={},f[27]={};
    stack<char> p;
	for(int i=0;i<s.length();i++) frq[s[i]-'a']++;
    for(int i=0;i<s.length();i++) f[s[i]-'a']++;
	for(int i=0,j=0;i<26;i++){
		while(frq[i]>0&&j<n){ 
            //cout<<j<<" "<<ans<<endl;
            while(!p.empty()&&p.top()-'a'<=i){
                ans+=p.top();
                frq[p.top()-'a']--;
                p.pop();
            }
            //cout<<ans<<endl;
            if(f[i]){ 
                //cout<<ans<<endl;
                f[s[j]-'a']--;
                p.push(s[j]);
                j++;
            }
            else{
                break;
            }
		}
    while(!p.empty()&&p.top()-'a'<=i){
            ans+=p.top();
            frq[p.top()-'a']--;
            p.pop();
        }
	}
    while(!p.empty()){
        ans+=p.top();
        p.pop();
    }
	cout<<ans<<endl;
}
