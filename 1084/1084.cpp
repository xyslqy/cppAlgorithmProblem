#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e4+10; 
int n,m;
vector<pair<int,int>> e[N];
int f[21][N],dis[21][N];
int jd[N];
void dfs(int x,int fa){
	for(auto _:e[x]){
		int y=_.first,w=_.second;
		if(y==fa){
			f[0][x]=fa;
			dis[0][x]=w;
			for(int i=1;i<=20;i++){
				f[i][x]=f[i-1][f[i-1][x]];
				dis[i][x]=dis[i-1][f[i-1][x]]+dis[i-1][x];
			}
			break;
		}
	}
	for(auto _:e[x]){
		int y=_.first;
		if(y!=fa){
			dfs(y,x);
		}
	}
}
bool vis[N];
bool dfs2(int x,int fa){
	if(vis[x]) return true;
	for(auto _:e[x]){
		int y=_.first;
		if(y!=fa){
			if(!dfs2(y,x)) return false;
		}
	}
	if(e[x].size()==1) return false;
	return true;
}
bool check(int t){
	memset(vis,0,sizeof(vis));
	priority_queue<int,vector<int>,greater<int>> b,c;
	vector<pair<int,int>> d;
	for(int i=1;i<=m;i++){
		int nu=jd[i];
		int nt=t;
		for(int i=20;i>=0;i--){
			if(f[i][nu]>1&&nt>=dis[i][nu]){
				nt-=dis[i][nu];
				nu=f[i][nu];
			}
		}
		if(nt<dis[0][nu]){
			vis[nu]=true;
		}
		else if(f[0][nu]==1&&nt<2*dis[0][nu]){
			d.push_back({nu,nt});
		}
		else{
			b.push(nt-dis[0][nu]);
		}
	}
	for(auto _:d){
		int nu=_.first,nt=_.second;
		if(!dfs2(nu,1)){
			vis[nu]=true;
		}else{
			b.push(nt-dis[0][nu]);
		}
	}
	for(auto _:e[1]){
		int y=_.first,w=_.second;
		if(!dfs2(y,1)){
			c.push(w);
		}
	}
	while(!b.empty()&&!c.empty()){
		int x=b.top();
		int y=c.top();
		b.pop();
		if(x>=y) c.pop();
	}
	if(c.empty()) return true;
	else return false;
}
signed main(){
//	freopen("P1084_1.in","r",stdin);
	cin>>n;
	int l=0,r=0;
	for(int i=1;i<n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
		r+=w;
	}
	dfs(1,0);
	cin>>m;
	for(int i=1;i<=m;i++) cin>>jd[i];
	int ans=-1;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)){
			r=mid-1;
			ans=mid;
		}
		else{
			l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
