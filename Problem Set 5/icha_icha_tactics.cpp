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
		string s;
		cin>>s;
		int a=0,b=0,flag=1;
		int n=s.length();
		for(int i=0;i<n;i++){
			if(s[i]=='{'){
				a++;
			}
			else if(s[i]=='}'){
				if(a>0){
					if(b>0&&b<=a){
                        a--;
                        b--;
                    }
					else{
						flag=0;
						break;
					}
				}
				else{
					flag=0;
					break;
				}
			}
			else if(s[i]=='1'){ 
				b++;
                if(i&&s[i]=='1'&&s[i-1]=='1'){
                    flag=0;
                    break;
                }
                if(b>a){
                    flag=0;
                    break;
                }                
			}
		} 
        if(a>0||b>0) flag=0;
		if(flag) puts("Yes");
		else puts("No");
	}
}