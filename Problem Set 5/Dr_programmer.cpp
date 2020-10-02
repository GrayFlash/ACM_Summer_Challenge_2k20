#include <iostream>
#include <algorithm>
using namespace std;
#define ll long
#define mod 1000000009
/*typedef pair<int,int> pp;
#define ff first 
#define ss second*/ 
#define pb push_back
#define lb lower_bound 
#define ub upper_bound 
int main(){
	int n,m,q;
	scanf("%d %d %d",&n,&m,&q);
	ll x[n],y[m];
	for(int i=0;i<n;i++) scanf("%ld",&x[i]);
	for(int i=0;i<m;i++) scanf("%ld",&y[i]);
	sort(x,x+n);
	sort(y,y+m);
	ll z,l1,r1,l2,r2,b;
	char c;
	while(q--){
		ll ans=0;
        scanf("%ld %c",&z,&c);
		if(c=='A'){
			scanf("%ld %ld",&l1,&r1);
			int i=lb(x,x+n,l1)-x; 
            int j=lb(x,x+n,r1)-x;  
            if(x[j]>r1) j--;
            else if(j==n) j=n-1;
            int k=m-1;
            while(i<=j&&k>=0){
                if(x[i]+y[k]<=z){
                    ans+=k+1;
                    i++;
                }
                else k--;
            }
		}
		else if(c=='B'){
			scanf("%ld %ld",&l1,&r1);
			int i=lb(y,y+m,l1)-y;
            int j=lb(y,y+m,r1)-y; 
            if(y[j]>r1) j--;
            else if(j==m) j=m-1;
            int k=n-1;
            while(i<=j&&k>=0){
                if(x[k]+y[i]<=z){
                    ans+=k+1;
                    i++;
                }
                else k--;
            }
		}
		else{
			scanf("%ld %ld %ld %ld",&l1,&r1,&l2,&r2);
			int i=lb(x,x+n,l1)-x;
            int j=lb(x,x+n,r1)-x;
            int k=lb(y,y+m,l2)-y;
            int s=lb(y,y+m,r2)-y;  
            if(x[j]>r1) j--;
            else if(j==n) j=n-1;
            if(y[s]>r2) s--;
            else if(s==m) s=m-1;
                while(j>=i&&s>=k){ 
                    if(y[k]+x[j]<=z){
                        ans+=(j-i+1); 
                        k++;
                    }
                    else j--;
                }
		}
		printf("%ld\n",ans);
	}
}