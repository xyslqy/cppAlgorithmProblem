#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,p,ans=1;
ll qpow(ll p,ll a){
	ll res=1;
	while(a){
		if(a&1) res=(res*p)%mod;
		p=(p*p)%mod;
		a>>=1;
	}
	return res;
}

int main(){
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		ll a;
		cin>>a;
		ans=(ans*(qpow(p,a)+1))%mod;
	}
	cout<<ans;
	return 0;
}

