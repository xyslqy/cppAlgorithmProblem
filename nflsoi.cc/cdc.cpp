#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,t;
int a,b;
int f[6005];
int main(){
	memset(f,0xcf,sizeof(f));
	cin>>n>>t;
	f[0]=0;
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		mx=max(mx,a);
		for(int j=t+a-1;j>=a;j--){
			f[j]=max(f[j-a]+b,f[j]);
		}
	}
	int ans=0;
	for(int i=0;i<=t+mx-1;i++){
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
}

