#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005];
int b[200005];
vector<pair<int,int> > s[200005];
signed main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		b[x]+=2;
		s[y].push_back({z,x});
		s[z].push_back({y,x});
	}
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(!b[i]){
			q.push(i);
			a[i]=1;
		}
	}
	int cnt=0;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(auto y:s[x]){
			a[y.second]=max(a[y.second],a[y.first]+a[x]);
			b[y.second]--;
			if(!b[y.second]){
				q.push(y.second);
			}
		}
		cnt++;
	}
	if(cnt!=n){
		cout<<-1;
		return 0;
	} 
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=a[i];
	}
	if(ans>1000000000){
		cout<<-1;
		return 0;
	}
	cout<<ans;
	return 0;
}

