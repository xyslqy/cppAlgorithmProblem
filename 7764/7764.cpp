#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,un,len,ans=0;
int a[N],num[N],cnt[N],ANS[N];
struct node{
	int l,r,id;
	bool operator < (const node &x) const {
		return (l/len==x.l/len)?(l/len%2==0?r<x.r:r>x.r):l<x.l;
	}
}q[N];
int main(){
	cin>>n>>m;
	len=sqrt(n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num[i]=a[i];
	}
	sort(num+1,num+1+n);
	un=unique(num+1,num+1+n)-num-1;
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(num+1,num+1+un,a[i])-num;
	}
	for(int i=1;i<=m;i++){
		cin>>q[i].l>>q[i].r;
		q[i].id=i;
	}
	sort(q+1,q+1+m);
	int l=1,r=0;
	for(int i=1;i<=m;i++){
		while(r<q[i].r){
			cnt[a[++r]]++;
			if(cnt[a[r]]==2) ans++;
			if(cnt[a[r]]==3) ans--;
		}
		while(r>q[i].r){
			cnt[a[r]]--;
			if(cnt[a[r]]==2) ans++;
			if(cnt[a[r]]==1) ans--;
			r--;
		}
		while(l<q[i].l){
			cnt[a[l]]--;
			if(cnt[a[l]]==2) ans++;
			if(cnt[a[l]]==1) ans--;
			l++;
		}
		while(l>q[i].l){
			cnt[a[--l]]++;
			if(cnt[a[l]]==2) ans++;
			if(cnt[a[l]]==3) ans--;
		}
		ANS[q[i].id]=ans;
	}
	for(int i=1;i<=m;i++) cout<<ANS[i]<<endl;
	return 0;
}

