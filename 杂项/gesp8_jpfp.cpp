#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7; 
int c[1005][1005];
int a[1005],t,n,m;
signed main(){
	for(int i=0;i<=1002;i++){
		for(int j=0;j<=1002;j++){
			if(i==j||j==0) c[i][j]=1;
			else c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
	}
	cin>>t;
	while(t--){
		cin>>n>>m;
		n=0;
		for(int i=1;i<=m;i++){
			cin>>a[i];
			n+=a[i];
		}
		int ans=1;
		for(int i=1;i<=m;i++){
			ans=ans*c[n][a[i]]%mod;
			n-=a[i];
		}
		cout<<ans<<endl;
	} 
	return 0;
}

