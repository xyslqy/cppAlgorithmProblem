#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
int n,m;
struct node{
	int x,y;
};
node a[100005];
bool cmp(node x,node y){
	return x.x<y.x;
}
signed main(){
	cin>>n>>m;
	int mi=0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		mi=min(mi,a[i].x+a[i].y);
	}
	sort(a+1,a+1+n,cmp);
	int ans=0;
	for(int i=0;i<=n;i++){
		if(m>=a[i].x){
			m-=a[i].x;
		}else{
			break;
		}
		ans=max(ans,m/mi*2+i);
	}
	cout<<ans;
	return 0;
}

