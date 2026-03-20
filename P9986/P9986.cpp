#include<bits/stdc++.h>
typedef unsigned long long ull;
int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-'){
            f=-1;
        }
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
const int maxn=1e5+10,maxm=1e6+10;
int n,m,un,len,ans,tot;
int a[maxn],b[maxn],ANS[maxm];
ull t[maxn];
std::unordered_map<int,int> mp;
struct node{
    int l,r,id;
}q[maxm];
bool cmp(node x,node y){
    if(x.l/len!=y.l/len) return x.l/len<y.l/len;
    if((x.l/len)%2==0) return x.r<y.r;
    return x.r>y.r;
}
inline void add(int x){
    int pos=x/60;
    ans-=__builtin_popcountll(t[pos]);
    t[pos]+=1ull<<(x%60);
    if(t[pos]>=(1ull<<60)){
        t[pos]-=1ull<<60;
        int p=pos+1;
        while(t[p]==(1ull<<60)-1ull){
            ans-=60;
            t[p]=0;
            p++;
        }
        ans-=__builtin_popcountll(t[p]);
        t[p]++;
        ans+=__builtin_popcountll(t[p]);
    }
    ans+=__builtin_popcountll(t[pos]);
}
inline void del(int x){
    int pos=x/60;
    ans-=__builtin_popcountll(t[pos]);
    if(t[pos]<(1ull<<(x%60))){
        t[pos]+=1ull<<60;
        int p=pos+1;
        while(t[p]==0){
            ans+=60;
            t[p]=(1ull<<60)-1ull;
            p++;
        }
        ans-=__builtin_popcountll(t[p]);
        t[p]--;
        ans+=__builtin_popcountll(t[p]);
    }
    t[pos]-=1ull<<(x%60);
    ans+=__builtin_popcountll(t[pos]);
}
int main(){
    n=read();
    m=read();
    len=sqrt(n);
    for(int i=1;i<=n;i++){
        a[i]=read();
        int p=a[i];
        while(mp[p]==1){
            mp[p]=0;
            p++;
        }
        mp[p]=1;
    }
    for(auto _:mp){
        b[++un]=_.first;
    }
    std::sort(b+1,b+1+un);
    un=std::unique(b+1,b+1+un)-b;
    for(int i=1;i<=n;i++){
        a[i]=std::lower_bound(b+1,b+1+un,a[i])-b-1;
    }
    for(int i=1;i<=m;i++){
        q[i].l=read();
        q[i].r=read();
        q[i].id=i;
    }
    std::sort(q+1,q+1+m,cmp);
    int l=1,r=0;
    for(int i=1;i<=m;i++){
        int id=q[i].id,ql=q[i].l,qr=q[i].r;
        while(r<qr)add(a[++r]);
        while(r>qr)del(a[r--]);
        while(l<ql)del(a[l++]);
        while(l>ql)add(a[--l]);
        ANS[id]=ans;
    }
    for(int i=1;i<=m;i++){
        printf("%d\n",ANS[i]);
    }
}
