#include<bits/stdc++.h>
#define ll long long
using namespace std;
int s[10],st,ed,c;
int h[10]={0,2,6,4,8,6,10,14};
vector<pair<int,int> > e[105];
int dis[105];
int vis[105];
struct node{
	int id,dis;
	bool operator < (const node& x) const {
		return dis>x.dis;
	}
};
priority_queue<node> pq;
int main(){
	for(int i=1;i<=7;i++){
		cin>>s[i];
	}
	cin>>st>>ed;
	cin>>c;
	for(int i=1;i<=c;i++){
		int u,v,w;
		cin>>u>>v>>w;
		if(s[w]){
			w=h[w]/2;
		}else{
			w=h[w];
		}
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	memset(dis,0x7f,sizeof(dis));
	dis[st]=0;
	pq.push({st,0});
	while(!pq.empty()){
		int x=pq.top().id;
		pq.pop();
		if(vis[x]) continue;
		vis[x]=true;
		for(auto _:e[x]){
			int y=_.first,w=_.second;
			if(dis[y]>dis[x]+w){
				dis[y]=dis[x]+w;
				pq.push({y,dis[y]});
			}
		}
	}
	cout<<dis[ed];
	return 0;
}

