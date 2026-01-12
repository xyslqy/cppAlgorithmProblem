#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k;
int sn[1000005];
int sm[1000005];
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=k;j+=i){
			sn[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=i;j<=k;j+=i){
			sm[j]++;
		}
	}
	ll ans=0;
	for(int i=1;i<=k;i++){
		ans+=(ll)i*sn[i]*sm[i];
	}
	cout<<ans;
	return 0;
}

