#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100000];
signed main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}

