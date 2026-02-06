#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+1;
int n,m,s;
vector<int> e[N];
int dfn[N],st[21][N],tot=0;
void dfs(int x,int f){
	dfn[x]=++tot;
	st[0][tot]=f;
	for(int y:e[x]){
		if(y==f) continue;
		dfs(y,x);
	}
}
int lca(int x,int y){
	if(x==y) return x;
	x=dfn[x];
	y=dfn[y];
	if(x>y) swap(x,y);
	int d=__lg(y-x);
	x++;
	return (dfn[st[d][x]]<dfn[st[d][y-(1<<d)+1]]?st[d][x]:st[d][y-(1<<d)+1]);
}
int main(){
	cin>>n>>m>>s;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(s,0);
	for(int i=1;i<=20;i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			st[i][j]=(dfn[st[i-1][j]]<dfn[st[i-1][j+(1<<i-1)]]?st[i-1][j]:st[i-1][j+(1<<i-1)]);
		}
	}
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		cout<<lca(a,b)<<"\n";
	}
	return 0;
}

