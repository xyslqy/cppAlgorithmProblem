#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
struct num{
	int n=0;
	int a[10000];
	
};
num operator * (const num &x,const num &y){
	num c;
	c.n=x.n+y.n;
	for(int i=1;i<=x.n;i++){
		for(int j=1;j<=y.n;j++){
			c.a[i+j-1]+=x.a[i]*y.a[i];
		}
	}
	int tmp=0;
	for(int i=1;i<=c.n;i++){
		c.a[i]+=tmp;
		c.a[i+1]+=c.a[i]%10;
		c.a[i]/=10;
	}
	for(int i=c.n;i>=2;i--){
		if(c.a[i]==0){
			c.n--;
		}
		else break;
	}
	return c;
}
struct node{
	int l,r;
};
node a[1005];
bool cmp(node x,node y){
	return x.l*x.r<y.l*y.r;
}
int ans=0;
signed main(){
	cin>>n;
	for(int i=0;i<=n;i++){
		cin>>a[i].l>>a[i].r;
	}
	sort(a+1,a+1+n,cmp);
	int tmp=a[0].l;
	for(int i=1;i<=n;i++){
		ans=max(ans,tmp/a[i].r);
		tmp*=a[i].l;
	}
	cout<<ans;
	return 0;
}

