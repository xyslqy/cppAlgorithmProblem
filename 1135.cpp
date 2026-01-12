#include<bits/stdc++.h>
using namespace std;
int n,a,b,k[1000];
bool bo[1000];
struct node{
	int x,y;
};
queue<node> q;
signed main(){
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++){
		cin>>k[i];
	}
	q.push(node{a,0});
	bo[a]=true;
	while(!q.empty()){
		int x=q.front().x;
		int y=q.front().y;
		q.pop();
		if(x==b){
			cout<<y;
			return 0;
		}
		if(x+k[x]<=n&&!bo[x+k[x]]){
			q.push(node{x+k[x],y+1});
			bo[x+k[x]]=true;
		}
		if(x-k[x]>0&&!bo[x-k[x]]){
			q.push(node{x-k[x],y+1});
			bo[x-k[x]]=false;
		}
	}
	cout<<-1;
	return 0;
}

