#include<bits/stdc++.h>
#define ll long long
#define pbi pair<bool,int>
using namespace std;
const int N=1e5+10;
int n,f;
int a[N],b[N],k[N],lth[N];
vector<int> e[N];

//shupo

int fa[N],siz[N],dep[N],son[N],dfn[N],top[N],tot=0;
void dfs1(int x,int f){
	fa[x]=f;
	siz[x]=1;
	dep[x]=dep[f]+1;
	for(int y:e[x]) if(y!=f){
		dfs1(y,x);
		siz[x]+=siz[y];
		if(siz[y]>siz[son[x]]){
			son[x]=y;
		}
	}
}
void dfs2(int x,int t){
	top[x]=t;
	dfn[x]=++tot;
	if(son[x]) dfs2(son[x],t);
	for(int y:e[x]) if(y!=fa[x]&&y!=son[x]){
		dfs2(y,y);
	}
}

int lca(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		u=fa[top[u]];
	}
	return dep[u]<dep[v]?u:v;
}

//segtree

struct node{
	int ls,rs;
	bool same=true;
	int val,lazy;
}t[4*N];
int root;
int New(int x){
	t[++tot].val=x;
	return tot;
}
void pushdown(int x){
	if(!t[x].ls) t[x].ls=New(t[x].val);
	if(!t[x].rs) t[x].rs=New(t[x].val);
	if(t[x].lazy){
		t[t[x].ls].val=t[x].lazy;
		t[t[x].rs].val=t[x].lazy;
		t[x].lazy=0;
	}
}
void pushup(int x){
	if(!t[x].ls) t[x].ls=New(t[x].val);
	if(!t[x].rs) t[x].rs=New(t[x].val);
	if(!t[t[x].ls].same||!t[t[x].rs].same) t[x].same=false;
	if(t[t[x].ls].val!=t[t[x].rs].val) t[x].same=false;
	else t[x].same=true;
}
pbi query(int x,int l,int r,int L,int R){
//	cerr<<x<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<" "<<t[x].same<<" "<<t[x].val<<endl;
	if(L<=l&&r<=R){
		return {t[x].same,t[x].val};
	}
	pushdown(x);
	int mid=l+r>>1;
	pbi a={true,-1},b={true,-1},c={true,-1};
	if(L<=mid) a=query(t[x].ls,l,mid,L,R);
	if(R>mid) b=query(t[x].rs,mid+1,r,L,R);
	if(a.first==false||b.first==false) c.first=false;
	else if(a.second!=-1&&b.second!=-1&&a.second!=b.second) c.first=false;
	else c.first=true;
	if(a.second==-1) c.second=b.second;
	else c.second=a.second;
	return c;
}
void upd(int x,int l,int r,int L,int R,int c){
	if(L<=l&&r<=R){
		t[x].val=c;
		t[x].lazy=c;
		t[x].same=true;
		return;
	}
	pushdown(x);
	int mid=l+r>>1;
	if(L<=mid) upd(t[x].ls,l,mid,L,R,c);
	if(R>mid) upd(t[x].rs,mid+1,r,L,R,c);
	pushup(x);
}

bool isame(int u,int v){
	int val=-2;
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		pbi c=query(root,1,n,dfn[top[u]],dfn[u]);
//		cerr<<c.second<<endl;
		if(!c.first) return false;
		if(val==-2) val=c.second;
		else if(val!=c.second) return false;
		u=fa[top[u]];
	}
	if(dep[u]>dep[v]) swap(u,v);
	pbi c=query(root,1,n,dfn[u],dfn[v]);
//	cerr<<c.second<<endl;
	if(!c.first) return false;
	if(val==-2) val=c.second;
	else if(val!=c.second) return false;
	return true;
}
void paint(int u,int v,int id){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		upd(root,1,n,dfn[top[u]],dfn[u],id);
		u=fa[top[u]];
	}
	if(dep[u]>dep[v]) swap(u,v);
	upd(root,1,n,dfn[u],dfn[v],id);
}

bool cmp(int x,int y){
	return lth[x]>lth[y];
}

int main(){
	cin>>n>>f;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(1,0);
	dfs2(1,1);
	tot=0;
	root=New(0);
	for(int i=1;i<=f;i++){
		k[i]=i;
		cin>>a[i]>>b[i];
		lth[i]=dep[a[i]]+dep[b[i]]-2*dep[lca(a[i],b[i])];
	}
	sort(k+1,k+1+f,cmp);
	for(int i=1;i<=f;i++){
		if(!isame(a[k[i]],b[k[i]])){
			cout<<"No";
			return 0;
		}
		paint(a[k[i]],b[k[i]],i);
	}
	cout<<"Yes";
	return 0;
}


