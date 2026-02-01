#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,INF=0x7fffffff;
struct Treap{
	int l,r;
	int val,dat;
	int cnt=0,siz=0;
}t[N];
int tot=0,root;
int New(int val){
	t[++tot].val=val;
	t[tot].dat=rand();
	t[tot].siz=t[tot].cnt=1;
	return tot;
}
void bud(){
	root=New(-INF);
	t[root].r=New(INF);
	return;
}
void zig(int &p){
	int q=t[p].l;
	t[p].l=t[q].r;
	t[q].r=p;
	p=q;
}
void zag(int &p){
	int q=t[p].r;
	t[p].r=t[q].l;
	t[q].l=p;
	p=q;
}
void upd(int p){
	t[p].siz=t[p].cnt+t[t[p].l].siz+t[t[p].r].siz;
}
void ins(int &p,int val){
	if(!p){
		p=New(val);
		return;
	}
	if(t[p].val==val){
		t[p].cnt++;
		upd(p);
		return;
	}
	if(val<t[p].val){
		ins(t[p].l,val);
		if(t[t[p].l].dat>t[p].dat){
			zig(p);
		}
	}else{
		ins(t[p].r,val);
		if(t[t[p].r].dat>t[p].dat){
			zag(p);
		}
	}
	upd(p);
	upd(t[p].l);
	upd(t[p].r);
	return;
}
void rm(int &p,int val){
	if(!p) return;
	if(t[p].val==val){
		if(t[p].cnt>1){
			t[p].cnt--;
			upd(p);
			return;
		}
		if(t[p].l||t[p].r){
			if(!t[p].l||t[t[p].r].dat>t[t[p].l].dat){
				zag(p);
				rm(t[p].l,val);
			}else{
				zig(p);
				rm(t[p].r,val);
			}
			upd(p);
		}else{
			p=0;
		}
		return;
	}
	val<t[p].val?rm(t[p].l,val):rm(t[p].r,val);
	upd(p);
}
int rnk(int p,int val){
	if(!p) return 1;
	if(t[p].val==val) return t[t[p].l].siz+1;
	if(val<t[p].val) return rnk(t[p].l,val);
	else return rnk(t[p].r,val)+t[p].cnt+t[t[p].l].siz;
}
int val(int p,int rnk){
	if(!p) return INF;
	if(t[t[p].l].siz>=rnk) return val(t[p].l,rnk);
	if(t[t[p].l].siz+t[p].cnt>=rnk) return t[p].val;
	else return val(t[p].r,rnk-t[p].cnt-t[t[p].l].siz);
}
int pre(int val){
	int p=root;
	int ans=1;
	while(p){
		if(t[p].val==val){
			if(t[p].l){
				p=t[p].l;
				while(t[p].r) p=t[p].r;
				ans=p; 
			}
			break;
		}
		if(t[p].val<val&&t[p].val>t[ans].val) ans=p;
		p=val<t[p].val?t[p].l:t[p].r;
	}
	return t[ans].val;
}
int nxt(int val){
	int p=root;
	int ans=2;
	while(p){
		if(t[p].val==val){
			if(t[p].r){
				p=t[p].r;
				while(t[p].l) p=t[p].l;
				ans=p; 
			}
			break;
		}
		if(t[p].val>val&&t[p].val<t[ans].val) ans=p;
		p=val<t[p].val?t[p].l:t[p].r;
	}
	return t[ans].val;
}
int n;
int main(){
	bud();
	cin>>n;
	while(n--){
		int o,x;
		cin>>o>>x;
		if(o==1) ins(root,x);
		if(o==2) rm(root,x);
		if(o==3) cout<<rnk(root,x)-1<<endl;
		if(o==4) cout<<val(root,x+1)<<endl;
		if(o==5) cout<<pre(x)<<endl;
		if(o==6) cout<<nxt(x)<<endl;
	}
	return 0;
} 
