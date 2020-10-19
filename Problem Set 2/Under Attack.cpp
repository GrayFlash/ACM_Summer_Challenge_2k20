#include <bits/stdc++.h>
#define FAST_A ios_base::sync_with_stdio(0)
#define FAST_B cin.tie(NULL)
using namespace std;

int main(){
	FAST_A;
	FAST_B;
	long long int t,m,n;
	cin>>t;
	while(t--){
		cin>>m;
		cin>>n;
		long long int sum=0;
		long long int ar[m][n];
		for(long long int i=0;i<m;i++){
			for(long long int j=0;j<n;j++){
				cin>>ar[i][j];
				sum+=ar[i][j];
			}
		}
//		cout<<sum<<endl;
  		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(ar[i][j]==0){
//				cout<<ar[i][j]<<endl;
				continue;
				}
				if(i!=0 && j!=0){
				if(ar[i-1][j-1]>ar[i][j]){
					sum-=ar[i][j];
//					cout<<ar[i][j]<<endl;
//					cout<<sum<<endl;
					continue;
				}
				}
				if(i!=0 && j<n-1){
				if(ar[i-1][j+1]>ar[i][j]){
					sum-=ar[i][j];
//					cout<<ar[i][j]<<endl;
//					cout<<sum<<endl;
					continue;
				}
				}
				if(j!=0 && i<m-1){
				if(ar[i+1][j-1]>ar[i][j]){
					sum-=ar[i][j];
//					cout<<ar[i][j]<<endl;
//					cout<<sum<<endl;
					continue;
				}
				}
				if(i!=0){
				if(ar[i-1][j]>ar[i][j]){
					sum-=ar[i][j];
//					cout<<ar[i][j]<<endl;
//					cout<<sum<<endl;
					continue;
				}
				}
				if(j!=0){
				if(ar[i][j-1]>ar[i][j]){
					sum-=ar[i][j];
//					cout<<ar[i][j]<<endl;
//					cout<<sum<<endl;
					continue;
				}
				}
				if(j<n-1){
				if(ar[i][j+1]>ar[i][j]){
					sum-=ar[i][j];
//					cout<<ar[i][j]<<endl;
//					cout<<sum<<endl;
					continue;
				}
				}
				if(i<m-1){
				if(ar[i+1][j]>ar[i][j]){
					sum-=ar[i][j];
//					cout<<ar[i][j]<<endl;
//					cout<<sum<<endl;
					continue;
				}
				}
				if(i<m-1 && j<n-1){
				if(ar[i+1][j+1]>ar[i][j]){
					sum-=ar[i][j];
//					cout<<ar[i][j]<<endl;
//					cout<<sum<<endl;
					continue;
				}
				}
			}
		}
		cout<<endl<<sum<<endl;
	}
	return 0;
}
