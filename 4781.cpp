#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,k;
ll x[2005];
ll y[2005];
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ll cnt=1;
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			cnt=(cnt*k%mod-cnt*x[j]%mod)/(x[i]-x[j])%mod;
		}
		ans=(ans+cnt*y[i]%mod)%mod;
	}
	cout<<ans;
	return 0;
}

