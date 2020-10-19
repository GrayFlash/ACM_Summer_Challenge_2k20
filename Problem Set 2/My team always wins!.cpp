#include <bits/stdc++.h>
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main(){
	boost;
	int n,k;
	cin>>n>>k;
	int ar[2][n];
	for(int i=0;i<2;i++){
		for(int j=0;j<n;j++){
			cin>>ar[i][j];
		}
	}
	int total=0,sum=0,max=0;
	for(int j=0;j<k;j++){
		if(ar[1][j]==0){
			sum+=ar[0][j];
		}
	}
	
	for(int i=0;i<n;i++){
		if(ar[1][i]==1){
			total+=ar[0][i];
		}
		if(i>0 && i<n-k+1){
			if(ar[1][i-1]==0)
			sum-= ar[0][i-1];
			if(ar[1][i+k-1]==0)
			sum+= ar[0][i+k-1];
		}
		if(max<sum){
			max=sum;
		}
	}

	max+=total;
	printf("%d\n",max);
	return 0;
}
