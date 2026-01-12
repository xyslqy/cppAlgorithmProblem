#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[505];
int f[505][505];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int k=2;k<=n;k++){
		memset(f,0,sizeof(f));
		for(int i=1;i<k;i++){
			for(int j=k;j<=n;j++){
				if(a[i]==a[j]) f[i][j]=f[i-1][j-1]+1;
				else f[i][j]=max(f[i-1][j],f[i][j-1]);
			}
		}
//		cout<<k<<" "<<f[k-1][n]<<endl;
//		for(int i=1;i<k;i++){
//			for(int j=k;j<=n;j++){
//				cout<<f[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		ans=max(ans,f[k-1][n]);
	}
	cout<<ans;
	return 0;
}

