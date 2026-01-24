#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
int map[10][10],n,x,y,z;
int f[10][10][10][10];
signed main(){
	cin>>n;
	while(true){
		cin>>x>>y>>z;
		if(x==0&&y==0&&z==0) break;
		map[x][y]=z;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				for(int l=1;l<=n;l++){
					int a=max(f[i-1][j][k-1][l],f[i-1][j][k][l-1]);
					int b=max(f[i][j-1][k-1][l],f[i][j-1][k][l-1]);
					f[i][j][k][l]=max(a,b)+map[i][j];
					if(k!=i||l!=j){
						f[i][j][k][l]+=map[k][l];
					}
				}
			}
		}
	}
	cout<<f[n][n][n][n];
	return 0;
}

