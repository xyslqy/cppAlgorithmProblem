#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read() {
    char cc = getchar(); int cn = 0, flus = 1;
    while(cc < '0' || cc > '9') {  if( cc == '-' ) flus = -flus;  cc = getchar();  }
    while(cc >= '0' && cc <= '9')  cn = cn * 10 + cc - '0', cc = getchar();
    return cn * flus;
}
const int N=1e5+10;
int n,m,un,len,cnt,sz;
int a[N],num[N],t[N],L[N],R[N],ad[N],b[N],w[N];
ll sum1[N],sum2[N],ans[N];
int gb(int x){
	return x/len;
}
struct Q{
	int l,r,id;
	bool operator < (const Q &x) const{
		return (gb(l)==gb(x.l))?r<x.r:l<x.l;
	}
}q[N];
struct node{
	int p,l,r,id;
};
vector<node> v1[N],v2[N];


void add(int x,int c){
	for(;x<=n;x+=x&-x) t[x]+=c; 
}
int sum(int x){
	int res=0;
	for(;x;x-=x&-x) res+=t[x];
	return res;
}

void md(){
	int l=1,r=0;
	for(int i=1;i<=m;i++){
		int ql=q[i].l,qr=q[i].r,id=q[i].id;
		if(r<qr){
			ans[id]+=sum1[qr]-sum1[r];
			v1[l].push_back({-1,r+1,qr,id});
			r=qr;
		}
		if(r>qr){
			ans[id]-=sum1[r]-sum1[qr];
			v1[l].push_back({1,qr+1,r,id});
			r=qr;
		}
		if(l<ql){
			ans[id]-=sum2[l]-sum2[ql];
			v2[r].push_back({1,l,ql-1,id});
			l=ql;
		}
		if(l>ql){
			ans[id]+=sum2[ql]-sum2[l];
			v2[r].push_back({-1,ql,l-1,id});
			l=ql;
		}
	}
}

void init(){
	cnt=sqrt(un);
	if(cnt*cnt<un) cnt++;
	sz=1;
	L[sz]=1;
	for(int i=1;i<=un;i++){
		b[i]=sz;
		if(i%cnt==0){
			R[sz]=i;
			L[++sz]=i+1;
		}
	}
	R[sz]=un;
}
void upd1(int x){
	for(int i=L[b[x]];i<=x;i++) w[i]++;
	for(int i=1;i<=b[x]-1;i++) ad[i]++;
}
void upd2(int x){
	for(int i=x;i<=R[b[x]];i++) w[i]++;
	for(int i=b[x]+1;i<=cnt;i++) ad[i]++;
}
void solve(){
	init();
	for(int i=1;i<=n;i++){
		int siz=v1[i].size(),l,r,id;
		ll p;
		for(int j=0;j<siz;j++){
			p=v1[i][j].p;
			l=v1[i][j].l;
			r=v1[i][j].r;
			id=v1[i][j].id;
			for(int k=l;k<=r;k++){
				ans[id]+=p*(w[a[k]+1]+ad[b[a[k]+1]]);
			}
		}
		upd1(a[i]);
	}
	memset(ad,0,sizeof(ad));
	memset(w,0,sizeof(w));
	for(int i=n;i>=1;i--){
		int siz=v2[i].size(),l,r,id;
		ll p;
		for(int j=0;j<siz;j++){
			p=v2[i][j].p;
			l=v2[i][j].l;
			r=v2[i][j].r;
			id=v2[i][j].id;
			for(int k=l;k<=r;k++){
				ans[id]+=p*(w[a[k]-1]+ad[b[a[k]-1]]);
			}
		}
		upd2(a[i]);
	}
}

int main(){
	n=read();
	m=read();
	len=sqrt(n);
	for(int i=1;i<=n;i++) num[i]=a[i]=read();
	for(int i=1;i<=m;i++) q[i].id=i,q[i].l=read(),q[i].r=read();
	
	sort(q+1,q+1+m);
	
	sort(num+1,num+1+n);
	un=unique(num+1,num+1+n)-num-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(num+1,num+1+un,a[i])-num;
	
	for(int i=1;i<=n;i++){
		sum1[i]=sum1[i-1]+i-1-sum(a[i]);
		add(a[i],1);
	}
	memset(t,0,sizeof(t));
	for(int i=n;i>=1;i--){
		sum2[i]=sum2[i+1]+sum(a[i]-1);
		add(a[i],1);
	}
	
	md();
	solve();
	
	for(int i=2;i<=m;i++){
		ans[q[i].id]+=ans[q[i-1].id];
	}
	for(int i=1;i<=m;i++){
		printf("%lld\n",ans[i]);
	}
	return 0;
} 
