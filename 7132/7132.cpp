#include<bits/stdc++.h>
#define int long long
using namespace std;
const int p=998244353;
int n,m;
int d[7005],f[7005][2],s[7005][2];
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>d[i];
	for(int i=0;i<=m;i++) s[i][1]=i+1;
	for(int i=2;i<=n;i++){
		for(int j=0; j<=m; j++){
			f[j][1]=(s[min(j+d[i-1],m)][0]+(j-d[i]<=0?0:p-s[j-d[i]-1][0])
						+s[m][1]+(j-d[i]<=0?0:p-s[j-d[i]-1][1]))%p;
			f[j][0]=(j-d[i]-1<0?0:(s[j-d[i]-1][1]+s[j-d[i]-1][0])%p);
		}
		s[0][1]=f[0][1];
		s[0][0]=f[0][0];
		for(int j=1; j<=m; j++){
			s[j][1]=(s[j-1][1]+f[j][1])%p;
			s[j][0]=(s[j-1][0]+f[j][0])%p;
		}
	}
	cout<<(s[m][0]+s[m][1])%p;
	return 0;
}

