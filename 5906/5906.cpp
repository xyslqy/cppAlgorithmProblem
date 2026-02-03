#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n,m,un,len,cn,bn;
int a[N],b[N],c[N],num[N],st[N],ed[N],ANS[N];
struct node{
	int l,r,id;
	bool operator < (const node &x) const {
		return (b[l]==b[x.l])?(r<x.r):(l<x.l); 
	}
}q[N];
int calc(int l,int r){
	int lst[N],ans=0;
	for(int i=l;i<=r;i++){
		lst[a[i]]=0;
	}
	for(int i=l;i<=r;i++){
		if(!lst[a[i]]) lst[a[i]]=i;
		ans=max(ans,i-lst[a[i]]);
	}
	return ans;
}
int main(){
	cin>>n;
	len=sqrt(n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num[i]=a[i];
		b[i]=(i-1)/len+1;
	}
	bn=b[n];
	sort(num+1,num+1+n);
	un=unique(num+1,num+1+n)-num-1;
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(num+1,num+1+un,a[i])-num;
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>q[i].l>>q[i].r;
		q[i].id=i;
	}
	sort(q+1,q+1+m);
	for(int i=1,j=1;j<=bn;j++){
		int ans=0,br=len*j,l=br+1,r=l-1;
		cn=0;
		for(;b[q[i].l]==j;i++){
			if(b[q[i].l]==b[q[i].r]){
				ANS[q[i].id]=calc(q[i].l,q[i].r);
				continue;
			}
			while(r<q[i].r){
				r++;
				if(!st[a[r]]){
					st[a[r]]=r;
				}
				ed[a[r]]=r;
				c[++cn]=a[r];
				ans=max(ans,r-st[a[r]]);
			}
			int tp=ans;
			while(l>q[i].l){
				l--;
				if(!ed[a[l]]){
					ed[a[l]]=l;
				}
				ans=max(ans,ed[a[l]]-l);
			}
			ANS[q[i].id]=ans;
			ans=tp;
			while(l<=br){
				if(ed[a[l]]==l) ed[a[l]]=0;
				l++;
			}
		}
		for(int i=1;i<=cn;i++){
			st[c[i]]=ed[c[i]]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ANS[i]<<endl;
	}
	return 0;
}

