#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1e9;
struct node{
	int _sum,_cnt;
	int lazy=0; 
	node(){
		_sum=0;
	}
	node(int x){
		_sum=x;
		_cnt=1;
	}
	void apply(int c){
		_sum+=_cnt*c;
		lazy+=c;
	}
}; 
node operator + (const node &a,const node &b){
	node c;
	c._sum=a._sum+b._sum;
	c._cnt=a._cnt+b._cnt;
	return c;
}

const int N=1e5+5;
node tree[N*4];
int a[N];

void build(int x,int l,int r){
	if(l==r){
		tree[x]=node(a[l]);
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	tree[x]=tree[x*2]+tree[x*2+1];
}
void push_down(int x){
	tree[x*2].apply(tree[x].lazy);
	tree[x*2+1].apply(tree[x].lazy);
	tree[x].lazy=0;
}
node query(int x,int l,int r,int ql,int qr){
	if(ql>r||qr<l) return node();
	if(ql<=l&&qr>=r) return tree[x];
	push_down(x);
	int mid=(l+r)/2;
	return query(x*2,l,mid,ql,qr)+query(x*2+1,mid+1,r,ql,qr);
}
void change_range(int x,int l,int r,int ql,int qr,int c){
	if(ql>r||qr<l) return;
	if(ql<=l&&qr>=r){
		tree[x].apply(c);
		return;
	}
	push_down(x);
	int mid=(l+r)/2;
	change_range(x*2,l,mid,ql,qr,c);
	change_range(x*2+1,mid+1,r,ql,qr,c);
	tree[x]=tree[x*2]+tree[x*2+1];
} 


signed main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	build(1,1,n);
	for(int i=0;i<m;i++){
		int c,d,e,f;
		cin>>c;
		if(c==1){
			cin>>d>>e>>f;
			change_range(1,1,n,d,e,f); 
		}
		if(c==2){
			cin>>d>>e;
			cout<<query(1,1,n,d,e)._sum<<endl;
		}
	}
	return 0;
}

