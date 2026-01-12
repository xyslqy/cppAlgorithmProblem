#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t,n,a[15005];
int lst[14];
int f[20][15005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		memset(lst,0,sizeof(lst));
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(lst[a[i]]) f[0][lst[a[i]]]=i+1;
			lst[a[i]]=i;
		}
		for(int i=n;i>=1;i--){
			for(int j=1;j<=19;j++){
				f[j][i]=f[j-1][f[j-1][i]];
			}
		}
		int q;
		cin>>q;
		while(q--){
			int ans=0;
			int l,r;
			cin>>l>>r;
			for(int i=l;i<=r;){
				for(int j=19;j>=0;j--){
					if(f[j][i]&&f[j][i]<=r+1) i=f[j][i];
				}
				if(i==r+1) break;
				i++;
				ans++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

