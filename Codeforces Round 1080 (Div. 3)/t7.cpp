#include<bits/stdc++.h>
using namespace std;
const int p=1e9+7,N=300000+10;
int t,n,q,cnt;
int f[N],l[N],r[N],fa[N];
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}
void write(int x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
    return;
}

int dfs(int x){
	if(f[x]) return f[x];
	f[x]=((long long)dfs(l[x])+dfs(r[x])+3)%p;
	return f[x];
}
int get(int x,int k){
	if(k>=f[x]) return get(fa[x],k-f[x]);
	if(k==0) return x;
	if(k-1<=f[l[x]]) return get(l[x],k-1);
	else return get(r[x],k-f[l[x]]-2);
}
int main(){
	t=read();
	while(t--){
		n=read();
		q=read();
		for(int i=1;i<=n;i++){
			l[i]=read();
			r[i]=read();
			if(!l[i]){
				f[i]=1;
			}
			else{
				f[i]=0;
				fa[l[i]]=i;
				fa[r[i]]=i;
			}
		}
		dfs(1);
		while(q--){
			int v,k;
			cin>>v>>k;
			write(get(v,k));
			putchar(' ');
		}
		puts("");
	}
	return 0;
}

