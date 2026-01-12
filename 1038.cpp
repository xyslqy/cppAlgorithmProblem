#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,p;
int c[105],u[105];
vector<pair<int,int> > e[105];
int in[105];
bool ans[105];
queue<int> q;
signed main(){
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		cin>>c[i]>>u[i];
	}
	for(int i=1;i<=p;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		in[v]++;
	}
	for(int i=1;i<=n;i++){
		if(in[i]==0){
			c[i]+=u[i];
			q.push(i);
		}
	}
	bool flag=true;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		c[x]-=u[x];
//		cout<<x<<" "<<c[x]<<endl;
		if(c[x]>0&&e[x].empty()){
			ans[x]=true;
			flag=false;
		}
		for(auto y:e[x]){
			in[y.first]--;
			if(c[x]>0) c[y.first]+=c[x]*y.second;
			if(!in[y.first]){
				q.push(y.first);
			}
		}
	}
	if(flag){
		cout<<"NULL";
	}else{
		for(int i=1;i<=n;i++){
			if(ans[i]){
				cout<<i<<" "<<c[i]<<"\n";
			}
		}
	}
	return 0;
}

