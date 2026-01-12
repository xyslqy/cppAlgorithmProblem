#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,r,c;
int a[100][100];
int f[100][100];
int sum[100];
int dis[100][100];
bool vis[100];
int ans=0x3f3f3f3f;
void work(){
	memset(f,0x3f,sizeof(f));
	memset(sum,0,sizeof(sum));
	memset(dis,0,sizeof(dis));
	for(int i=1;i<=n;i++){
		int last=0;
		for(int j=1;j<=m;j++){
			if(vis[j]){
				if(last){
					sum[i]+=abs(a[i][j]-a[i][last]);
				}
				last=j;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=m;k++){
				if(vis[k]) dis[i][j]+=abs(a[i][k]-a[j][k]);
			}
		}
	}
	for(int i=0;i<=n;i++) f[i][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=r;j++){
			for(int k=0;k<i;k++){
				f[i][j]=min(f[i][j],f[k][j-1]+sum[i]+dis[k][i]);
			}
		}
	}
	int mi=0x3f3f3f3f;;
	for(int i=1;i<=n;i++) mi=min(mi,f[i][r]);
	ans=min(mi,ans);
	return;
}
void dfs(int last,int cnt){
	if(cnt==c){
		work();
		return;
	} 
	for(int i=last+1;i<=m;i++){
		vis[i]=true;
		dfs(i,cnt+1);
		vis[i]=false;
	}
	return;
}
int main(){
	cin>>n>>m>>r>>c;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}

