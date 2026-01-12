#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[10000],b[10000],c[10000],f[10000][10000];
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=2000;
		}
		f[i][i]=0;
	}
	int d,e,g;
	for(int i=1;i<=m;i++){
		cin>>d>>e>>g;
		if(f[d][e]<g) continue;
		a[i]=d;b[i]=e;c[i]=g;
		f[a[i]][b[i]]=c[i];
		f[b[i]][a[i]]=c[i];
	}
	for(int i=1;i<=n;i++){
		for(int k=1;k<=n;k++){
			for(int j=1;j<=n;j++){
				if(f[k][j]>f[k][i]+f[i][j]){
					f[k][j]=f[k][i]+f[i][j];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<f[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

