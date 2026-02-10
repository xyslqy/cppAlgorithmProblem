#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
struct node{
	int l,r;
	mutable bool v;
	node (const int &il,const int &ir,const int &iv):l(il),r(ir),v(iv) {}
	bool operator < (const node &x) const {
		return l<x.l;
	}
};
set<node> st;
auto split(int x){
	auto it=st.lower_bound(node(x,0,0));
	if(it!=st.end()&&it->l==x) return it;
	--it;
	int l=it->l,r=it->r,v=it->v;
	st.erase(it);
	st.insert(node(l,x-1,v));
	return st.insert(node(x,r,v)).first; 
}
void upd(int l,int r){
	auto itr=split(r+1),itl=split(l);
	for(auto it=itl;it!=itr;it++){
		if(it->v) ans-=(it->r)-(it->l)+1;
	}
	st.erase(itl,itr);
	st.insert(node(l,r,0));
}
int main(){
	cin>>n>>m;
	st.insert(node(1,n,1));
	ans=n;
	while(m--){
		int l,r;
		cin>>l>>r;
		upd(l,r);
		cout<<ans<<endl;
	} 
	return 0;
}

