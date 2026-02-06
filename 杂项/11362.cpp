#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7,N=1e5+1;
int t;
int n,m,v;
pair<int,int> a[N];
int qpow(int x,int y){
	int res=1;
	while(y){
		if(y&1) res=res*x%mod;
		y>>=1;
		x=x*x%mod;
//		cout<<y;
	}
	return res;
}
int solve(int v,int x){
	int res=qpow(v,x*2);
	res+=mod;
	res-=qpow(v,x);
	res%=mod;
	res+=qpow(v,x-1);
	res%=mod;
	return res;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m>>v;
		for(int i=1;i<=m;i++){
			cin>>a[i].first>>a[i].second;
		}
		int last=0,ans=1;
		sort(a+1,a+1+m);
		bool flag=false;
		for(int i=2;i<=m;i++){
			if(a[i].first==a[i-1].first){
				if(a[i].second!=a[i-1].second){
					cout<<"0\n";
					flag=true;
					break;
				}
				continue;
			}
			int x=a[i].first-a[i-1].first;
			ans=(ans*solve(v,x))%mod;
		}
		if(flag) continue;
		ans=ans*qpow(v,2*(a[1].first-1))%mod;
		ans=ans*qpow(v,2*(n-a[m].first))%mod;
		cout<<ans<<"\n";
	}
	return 0;
}

