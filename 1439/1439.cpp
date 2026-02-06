#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100000],b[100000],c[100000];
int dp[100000];
signed main(){
	cin>>n;
	
	for(int i=0;i<n;i++){
		int j;
		cin>>j;
		b[j]=i;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
		c[i]=b[a[i]];
		dp[i]=1e9;
	}
	for(int i=0;i<n;i++){
		int j=upper_bound(dp,dp+n,c[i])-dp;
		dp[j]=c[i];
	}
	return 0;
}

