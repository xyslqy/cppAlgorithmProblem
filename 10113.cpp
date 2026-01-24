#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,q,m;
vector<int> g[300005];
int f[20][300005],s[300005],dep[300005];
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	s[x]=max(x,s[fa]);
	for(int i=1;i<=19;i++){
		f[i][x]=f[i-1][f[i-1][x]];
	}
	for(int y:g[x]) if(y!=fa){
		dfs(y,x);
	}
}
int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=19;i>=0;i--){
		if(dep[f[i][u]]>=dep[v]) u=f[i][u];
	}
	if(u==v) return u;
	for(int i=19;i>=0;i--){
		if(f[i][u]!=f[i][v]){
			u=f[i][u];
			v=f[i][v];
		}
	}
	return f[0][u];
}
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>f[0][i];
		g[f[0][i]].push_back(i);
	}
	dfs(0,0);
	cin>>q;
	while(q--){
		cin>>m;
		int lc;
		cin>>lc;
		for(int i=1;i<m;i++){
			int x;
			cin>>x;
			lc=lca(lc,x);
		}
		cout<<s[lc]<<endl;
	}
	return 0;
}

