#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,f[10000][10000],ans=0;
bool g[1000][1000];
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=2000;
		}
		f[i][i]=0;
	}
	int a,b,c;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		if(f[a][b]<c) continue;
		f[a][b]=c;
		f[b][a]=c;
		g[a][b]=true;
		g[b][a]=true;
	}
	for(int i=1;i<=n;i++){
		for(int k=1;k<=n;k++){
			for(int j=1;j<=n;j++){
				if(f[k][j]>f[k][i]+f[i][j]){
					f[k][j]=f[k][i]+f[i][j];
					if(g[k][j]){
						ans++;
						g[k][j]=false;
					}
				}
			}
		}
	}
	cout<<ans/2;
	return 0;
}

