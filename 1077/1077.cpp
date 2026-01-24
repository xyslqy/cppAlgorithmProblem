#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[101],mod=1e6+7;
int f[101][101];
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			for(int k=0;k<=min(j,a[i]);k++){
				f[i][j]=(f[i][j]+f[i-1][j-k])%mod;
			}
		}
	}
	cout<<f[n][m];
	return 0;
}

