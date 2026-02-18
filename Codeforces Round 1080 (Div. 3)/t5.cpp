#include<bits/stdc++.h>
using namespace std;
const int p=1e9+7,N=300000+10;
int t,n,cnt;
int f[N],l[N],r[N],ans[N];
int dfs(int x){
	if(f[x]) return f[x];
	f[x]=((long long)dfs(l[x])+dfs(r[x])+3)%p;
	return f[x];
}
void get(int x){
	ans[x]=cnt;
	if(l[x]==0) return;
	int tmp=cnt;
	cnt=((long long)tmp+f[l[x]])%p;
	get(l[x]);
	cnt=((long long)tmp+f[r[x]])%p;
	get(r[x]);
	cnt=tmp;
	return;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>l[i]>>r[i];
			if(!l[i]){
				f[i]=1;
			}
			else{
				f[i]=0;
			}
		}
		dfs(1);
		cnt=f[1];
		get(1);
		for(int i=1;i<=n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

