
#include <bits/stdc++.h>
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main(){
	boost;
	unsigned long long int n;
	unsigned long long int k;

	scanf("%llu",&n);
	scanf("%llu",&k);
	unsigned long long int ar[n];
	for(unsigned long long int i=0;i<n;i++){
		scanf("%llu",&ar[i]);
	}
	unsigned long long int a=0,b=0;
	unsigned long long int sum=0;
	for(unsigned long long int i=0;i<n-1;i++){
		for(unsigned long long int j=i+1;j<n;j++){
			if(ar[i]>ar[j]){
				++a;
			}			
			else if(ar[i]<ar[j]){
				++b;
			}
		}
	}
	unsigned long long int p=1000000007;
	unsigned long long int A= ((k*(k+1))/2)%p;
	unsigned long long int B= (((k-1)*k)/2)%p;
	sum = ((a*A) + (b*B))%p;
	
	cout<< sum;

	return 0;
}
