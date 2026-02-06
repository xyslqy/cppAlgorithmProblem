#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[10000],l[10000],r[10000],ans=0;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l[i]=max(l[i-1],a[i]);
	}
	for(int i=n;i>0;i--){
		r[i]=max(r[i+1],a[i]);
	}
	for(int i=2;i<=n-1;i++){
		if(a[i]<min(l[i],r[i])){
			ans+=min(l[i],r[i])-a[i];
		}
	}
	cout<<ans;
	return 0;
}

