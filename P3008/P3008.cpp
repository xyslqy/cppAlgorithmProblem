#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t,r,p,s;
vector<pair<int,int> > rd[50005],pl[50005];
int f[50005];
int find(int x){
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
void merge(int u,int v){
	int fu=find(u);
	int fv=find(v);
	f[fu]=fv;
}
int in[50005],dis[50005];
bool vis[50005];
struct node{
	int id;
	int dis;
	bool operator < (const node& x) const {
		return dis>x.dis;
	}
};
priority_queue<node> q;
vector<int> block[50005];
int main(){
	cin>>t>>r>>p>>s;
	for(int i=1;i<=t;i++) f[i]=i;
	for(int i=0;i<r;i++){
		int a,b,c;
		cin>>a>>b>>c;
		merge(a,b);
		rd[a].push_back({b,c});
		rd[b].push_back({a,c});
	}
	for(int i=0;i<p;i++){
		int a,b,c;
		cin>>a>>b>>c;
		in[find(b)]++;
		pl[a].push_back({b,c});
	}
	for(int i=1;i<=t;i++){
		block[find(i)].push_back(i);
	}
	memset(dis,0x3f,sizeof(dis));
	queue<int> Q;
	cerr<<dis[0]<<endl;
	dis[s]=0;
	Q.push(find(s));
	for(int i=1;i<=t;i++){
		if(in[i]==0) Q.push(i);
	}
	while(!Q.empty()){
		int bl=Q.front();
		Q.pop();
		for(int i:block[bl]) q.push({i,dis[i]});
		while(!q.empty()){
			int x=q.top().id;
			q.pop();
			if(vis[x]) continue;
			vis[x]=true;
			for(auto _:rd[x]){
				int y=_.first,w=_.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({y,dis[y]});
				}
			}
			for(auto _:pl[x]){
				int y=_.first,w=_.second;
				in[find(y)]--;
				if(in[find(y)]==0) Q.push(find(y));
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
				}
			}
		}
	}
	for(int i=1;i<=t;i++){
		if(dis[i]<100000000){
			cout<<dis[i]<<endl;
		}else{
			cout<<"NO PATH"<<endl;
		}
	}
	return 0;
}

