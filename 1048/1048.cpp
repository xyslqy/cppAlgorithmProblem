#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,m;
int a[101],b[101],f[101][1001]; 
signed main(){
	cin>>t>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<=t;j++){
			if(j>=a[i]){
				f[i][j]=max(f[i-1][j-a[i]]+b[i],f[i-1][j]);
			}else{
				f[i][j]=f[i-1][j];
			}
		}
	}
	cout<<f[m][t];
	return 0;
}

