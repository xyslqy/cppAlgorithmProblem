#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+1;
int n,m;
int ga[N],gb[N];
ll f[25][N][2],da[25][N][2],db[25][N][2];
struct city{
	int id,h;
	int pre,nxt;
};
city c[N];
int pos[N];
bool cmp(city a,city b){
	return a.h<b.h;
}
int choose(int x,int y,int i){
	if(!x) return c[y].id;
	if(!y) return c[x].id;
	if(c[i].h-c[x].h<=c[y].h-c[i].h) return c[x].id;
	else return c[y].id;
}
void del(int x){
	if(c[x].pre) c[c[x].pre].nxt=c[x].nxt;
	if(c[x].nxt) c[c[x].nxt].pre=c[x].pre;
}
void build(){
	for(int i=1;i<=n;i++){
		c[i].pre=i-1;
		c[i].nxt=i+1;
		pos[c[i].id]=i;
	}
	c[1].pre=0;
	c[n].nxt=0;
	for(int i=1;i<n;i++){
		int p=pos[i];
		int p1=c[p].pre;
		int p2=c[p].nxt;
		if(p1&&(c[p].h-c[p1].h<=c[p2].h-c[p].h||!p2)){
			gb[i]=c[p1].id;
			ga[i]=choose(c[p1].pre,p2,p);
		}
		else{
			gb[i]=c[p2].id;
			ga[i]=choose(p1,c[p2].nxt,p);
		}
		del(p);
	}
	for(int i=1;i<=n;i++){
		if(ga[i]){
			f[0][i][0]=ga[i];
			da[0][i][0]=abs(c[pos[i]].h-c[pos[ga[i]]].h);
			db[0][i][0]=0;
		}
		if(gb[i]){
			f[0][i][1]=gb[i];
			da[0][i][1]=0;
			db[0][i][1]=abs(c[pos[gb[i]]].h-c[pos[i]].h);
		}
	}
	for(int i=1;i<=24;i++){
		for(int j=1;j<=n;j++){
			for(int k=0;k<=1;k++){
				int l=(i==1)?k^1:k;
				if(f[i-1][j][k]) f[i][j][k]=f[i-1][f[i-1][j][k]][l];
				if(f[i][j][k]){
					da[i][j][k]=da[i-1][j][k]+da[i-1][f[i-1][j][k]][l];
					db[i][j][k]=db[i-1][j][k]+db[i-1][f[i-1][j][k]][l];
				}
			}
		}
	}
}
ll la,lb;
void calc(int s,ll x){
	la=lb=0;
	int k=0;
	for(int i=24;i>=0;i--){
		if(f[i][s][k]&&da[i][s][k]+db[i][s][k]<=x){
			la+=da[i][s][k];
			lb+=db[i][s][k];
			x-=da[i][s][k]+db[i][s][k];
			if(i==0) k^=1;
			s=f[i][s][k];
		}
	}
}
ll x;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i].h;
		c[i].id=i;
	}
	sort(c+1,c+1+n,cmp);
	build();
	cin>>x;
	int ansa=1,ansb=0,p=0;
	for(int i=1;i<=n;i++){
		calc(i,x);
		if(!lb) la=1;
		if(ansa*lb>ansb*la||(ansa*lb==ansb*la&&c[pos[p]].h<c[pos[i]].h)){
			ansa=la;
			ansb=lb;
			p=i;
		}
	}
	cout<<p<<"\n";
	cin>>m; 
	while(m--){
		ll x,s;
		cin>>s>>x;
		calc(s,x);
		cout<<la<<" "<<lb<<"\n";
	}
	return 0;
}

