#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int maxn=1e5+10,siz=1570;
int n,m,q,t,c;
ull bt[maxn][siz];
vector<int> e[maxn];
int a[maxn],b[maxn],b2a[maxn],b2id[maxn];
int tot=0,xx[maxn],yy[maxn],now[maxn];
void solve(){
    tot=0;
    memset(now,0,sizeof(now));
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++) e[i].clear();
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        b2a[b[i]]=a[i];
        b2id[b[i]]=i;
    }
    for(int x=n;x>=1;x--){
        memset(bt[x],0,sizeof(bt[x]));
        bt[x][b[x]>>6]=1ull<<(b[x]&63);
        for(int y:e[x]){
            for(int i=0;i<siz;i++){
                bt[x][i]|=bt[y][i];
            }
        }
    }
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            int x,y;
            cin>>x>>y;
            swap(b2a[b[x]],b2a[b[y]]);
        }
        else if(op==2){
            int x,y;
            cin>>x>>y;
            xx[++tot]=b[x];
            yy[tot]=b[y];
            swap(b2a[b[x]],b2a[b[y]]);
            swap(b2id[b[x]],b2id[b[y]]);
            swap(b[x],b[y]);
        }else{
            int x,l,r;
            cin>>x>>l>>r;
            while(now[x]<tot){
                ++now[x];
                int a=bt[x][xx[now[x]]>>6]>>(xx[now[x]]&63)&1;
                int b=bt[x][yy[now[x]]>>6]>>(yy[now[x]]&63)&1;
                if(a==b) continue;
                if(a){
                    bt[x][xx[now[x]]>>6]-=(1ull<<(xx[now[x]]&63));
                    bt[x][yy[now[x]]>>6]+=(1ull<<(yy[now[x]]&63));
                }else{
                    bt[x][xx[now[x]]>>6]+=(1ull<<(xx[now[x]]&63));
                    bt[x][yy[now[x]]>>6]-=(1ull<<(yy[now[x]]&63));
                }
            }
            bool flag=false;
            for(int i=siz-1;i>=0;i--){
                ull tmp=bt[x][i];
                while(tmp){
                    int nb=__lg(tmp)+(i<<6);
                    if(l<=b2a[nb]&&b2a[nb]<=r){
                        cout<<nb<<"\n";
                        flag=true;
                        break;
                    }
                    tmp-=1ull<<__lg(tmp);
                }
                if(flag) break;
            }
            if(!flag) cout<<0<<"\n";
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>t;
    while(t--){
        solve();
    }
    return 0;
}
