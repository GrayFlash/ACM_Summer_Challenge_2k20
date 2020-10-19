#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >>n;
	double ar[n][3];
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cin>> ar[i][j];
		}
	}
	for(int i=0;i<n;i++){
		int k=(ar[i][0]*ar[i][0])==(4*ar[i][1]*ar[i][2]);
		if(k)
		cout<< "YES" <<"\n";
		else
		cout<< "NO" <<"\n";
	}

	return 0;
}





















