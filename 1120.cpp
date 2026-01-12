#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,cnt;
int a[70];
int net[70];
bool vis[70];
bool dfs(int k,int last,int rest){
	if(rest==0){
		if(k==m)                return true;
		int i=0;
		while(vis[++i]); 
		if(dfs(k+1,i,cnt/m)) return true;
		else                    return false;
	}
	int l=last,r=n,mid;
	while(l<r){
		mid=(l+r)/2;
		if(a[mid]>rest){
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	for(int i=l;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=true;
		if(dfs(k,i,rest-a[i])) return true;
		vis[i]=false;
		if(a[i]==rest) return false;
		if(rest==cnt/m) return false;
		i=net[i]-1;
	}
	return false;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	cin>>n;
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt+=a[i];
		mx=max(mx,a[i]);
	}
	sort(a+1,a+n+1,cmp);
	int l=n+1;
	for(int i=n;i>=1;i--){
		if(a[i]!=a[i+1]) l=i+1;
		net[i]=l;
	}
	for(int i=mx;i<=cnt/2;i++){
		if(cnt%i!=0) continue;
		m=cnt/i;
		if(dfs(1,1,i)){
			cout<<i;
			return 0;
		}
	}
	cout<<cnt;
	return 0;
}

