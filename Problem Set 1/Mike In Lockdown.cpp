#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,n,k;
	cin>>t;
	for(int p=0;p<t;p++){
	int count=0;
	cin>>n;
	int ar[3][n];
	for(int i=0;i<3;i++){
		for(int j=0;j<n;j++){
			cin >> ar[i][j];
		}
	}
	for(int j=0;j<n;j++){
		k = ar[0][j]+ar[1][j];
		if(k>ar[2][j]){
			count+= k-ar[2][j];
		}
	}
	cout<< count<<endl;
	}
	return 0;
}
