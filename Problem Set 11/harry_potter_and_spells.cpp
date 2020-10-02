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
int n,count;
//vector<ll> dp(1e5+7,-1e18),a(1e5+7);
int main(){
	cin>>n; 
	ll a[n+1];
    //count=0;
	ll sum=1e10,ans=0,neg=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]<0){ 
			ans+=-a[i];
			neg++;
		}
		else ans=(a[i]+ans);
		sum=min(sum,abs(a[i]));
	}
	//cout<<solve(1)<<"\n";
	if(neg%2) ans-=sum*2;
    cout<<ans;
}