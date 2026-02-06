#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[100000];
bool moni(int l){
	int b,d;
	int c=m;
	for(int i=0;i<n-1;i++){
		d=a[i+1]-a[i];
		b=(d+l-1)/l-1;
		c-=b;
		if(c<0){
			return false;
		}
	}
	return true;
}
signed main(){
	cin>>n>>m;
	m++;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int l=1,r=a[n-1];
	int mid,ans=-1;
	while(l<=r){
		mid=(l+r)/2;
		if(moni(mid)){
			r=mid-1;
			ans=mid;
		}else{
			l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}

