#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;
int t,n;
int tn[N];
struct node{
	int id;
	int k=0;
	vector<int> t;
	bool operator < (const node &x) const {
		return k>x.k;
	}
}q[N];
void solve(){
	memset(tn,0,sizeof(tn));
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>q[i].k;
		q[i].t.clear();
		q[i].id=i;
		for(int j=1;j<=q[i].k;j++){
			int x;
			cin>>x;
			q[i].t.push_back(x);
		}
	}
	sort(q+1,q+1+n);
	for(int i=1;i<=n;i++){
		int col=0;
		for(int x:q[i].t){
			if(tn[x]) col=q[col].k<q[tn[x]].k&&col?col:tn[x];
		}
		if(col){
			for(int x:q[i].t){
				if(tn[x]!=col){
					cout<<"YES"<<endl;
					cout<<q[col].id<<" "<<q[i].id<<endl;
					return;
				}
			}
		}
		for(int x:q[i].t){
			tn[x]=i;
		}
	}
	cout<<"NO"<<endl;
	return;
}
signed main(){
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
