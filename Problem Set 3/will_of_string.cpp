#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main() {
	// your code goes here
	int t; 
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		vector<int> d1(n); 
		ll ans=0;
		for(int i=0,l=0,r=-1;i<n;i++){
			int k=i>r?1:min(d1[l+r-i],r-i+1);
			while((i+k)<n&&(i-k)>=0&&s[i-k]==s[i+k]) k++;
			d1[i]=k;
            k--;
			if(i+k>r){
				r=i+k;
				l=i-k;
			}
		}
		vector<int> d2(n);
		for(int i=0,l=0,r=-1;i<n;i++){
			int k=i>r?0:min(d2[l+r-i+1],r-i+1);
			while((i+k)<n&&(i-k-1)>=0&&s[i-k-1]==s[i+k]) k++;
			d2[i]=k;
            k--;
			if(i+k>r){
				l=i-k-1;
				r=i+k;
			}
		}
		for(int i=0;i<n;i++){
            //cout<<d1[i]<<" "<<d2[i]<<"\n";
			ans+=d1[i]+d2[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
