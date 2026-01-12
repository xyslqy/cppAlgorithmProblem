#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
int dfs(int n,int m,int k){
	int ans=1,tmp=0;
	for(int i=1;i<=n;i=tmp+1){
		tmp=n/(n/i);
		if(tmp>k+1){
			ans=max(ans,n/(k+1)*m);
            break;
		}
		ans=max(ans,(n/tmp)*(m/(k-tmp+2)));
	}
	return ans;
}
signed main(){
	cin>>n>>m>>k;
	if(k>n+m-2){
		cout<<-1;
	}else{
		cout<<dfs(n,m,k);
	}
	return 0;
}

