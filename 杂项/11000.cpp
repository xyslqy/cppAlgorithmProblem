#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
ll ans=1;
ll qpow(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
int main(){
	ans=qpow(9,10000);
	ans=(ans+mod-qpow(8,10000))%mod;
	ans=(ans+mod-qpow(8,10000))%mod;
	ans=(ans+qpow(7,10000))%mod;
	cout<<ans;
	return 0;
}

