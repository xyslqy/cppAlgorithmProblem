#include<bits/stdc++.h>
#define ll long long
using namespace std;
int m,n;
vector<pair<pair<int,int>,int> > e[105][505];
void sets(int l,int x){
	for(int i=1;i<=m;i++){
		e[l][x].push_back({{i,x},1});
	}
}
struct node{
	int l,x,w;
	bool operator < (const node& x) const {
		return w>x.w;
	}
};
int dis[105][505];
bool vis[105][505];
priority_queue<node> pq;
int main(){
	cin>>m>>n;
	string s;
	getline(cin,s);
	for(int i=1;i<=m;i++){
		getline(cin,s);
//		cerr<<s<<endl;
		int a,b=0,p=0;
		while(s[p]>='0'&&s[p]<='9'){
			b*=10;
			b+=s[p]-'0';
			p++;
		}
		
		sets(i,b);
		while(p<s.length()-1){
			a=0;
			while(s[p]<'0'||s[p]>'9') p++;
			while(s[p]>='0'&&s[p]<='9'){
				a*=10;
				a+=s[p]-'0';
				p++;
			}
			e[i][b].push_back({{i,a},0});
			sets(i,a);
			b=a;
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++) pq.push({i,1,0}),dis[i][1]=0;
	while(!pq.empty()){
		node x=pq.top();
		pq.pop();
		if(vis[x.l][x.x]) continue;
		vis[x.l][x.x]=true;
		for(auto _:e[x.l][x.x]){
			int yl=_.first.first,yx=_.first.second,w=_.second;
			if(dis[yl][yx]>dis[x.l][x.x]+w){
				dis[yl][yx]=dis[x.l][x.x]+w;
//				cerr<<x.l<<" "<<x.x<<" "<<yl<<" "<<yx<<" "<<w<<endl;
				pq.push({yl,yx,dis[yl][yx]});
			}
		}
	}
	int ans=0x3f3f3f3f;
	for(int i=1;i<=m;i++){
		ans=min(dis[i][n],ans);
	}
	if(ans!=0x3f3f3f3f){
		cout<<ans;
	}else{
		cout<<"NO";
	}
	return 0;
}

