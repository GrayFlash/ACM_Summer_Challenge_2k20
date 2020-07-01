#include<bits/stdc++.h>
#define intt long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main()
{
fast;
intt T;
cin>>T;
while(T--)
{
    intt num;
	cin>>num;
	vector<int> arr;
	int pos = -1;
	while (num>0){
		arr.push_back(num%3);
		if (arr.back() == 2) 
            pos = int(arr.size()) - 1;
		num /= 3;
	}
	arr.push_back(0);
	if (pos != -1) {
		int pos_ini = find(arr.begin() + pos, arr.end(), 0) - arr.begin();
		arr[pos_ini] = 1;
		for (int i = pos_ini - 1; i >= 0; --i) {
			arr[i] = 0;
		}
	}
	intt ans = 0;
	intt pow = 1;
	for (int i=0; i < int(arr.size()); i++) {
		ans += pow*arr[i];
		pow *= 3;
	}
	if (arr.back() == 1) 
        ans = pow / 3;
	cout <<ans<<"\n";
}
}