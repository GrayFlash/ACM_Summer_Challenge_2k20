#include <bits/stdc++.h>
#define LINT long long
using namespace std;

LINT smaller(LINT x,LINT y){
	if(x>=y)
	return y;
	else
	return x;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	LINT n,m,k;
	cin>> n;
	LINT ar[4],c[n];
	for(LINT i=0;i<n;i++){
		m =0;
		k =0;
		for(int j=0;j<4;j++){
			cin >> ar[j];
		}
		k = smaller(ar[2],ar[3]);
		m = k + ar[0];
		c[i]= smaller(m,ar[1]);	
	}
	for(LINT i=0;i<n;i++){
		cout<< c[i] << endl;
	}
	return 0;
}
