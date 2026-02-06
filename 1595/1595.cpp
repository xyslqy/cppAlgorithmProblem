#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll fact[21];
void init(){
	fact[1]=1;
	for(int i=2;i<=20;i++){
		fact[i]=fact[i-1]*i;
	}
}
ll c(ll n,ll m){
	return fact[n]/fact[m];
}
ll n;
int main(){
	cin>>n;
	init();
	ll ans=fact[n];
	for(int i=1;i<=n;i++){
		ans=ans+(i%2==1?-1:1)*c(n,i);
	}
	cout<<ans;
	return 0;
}

