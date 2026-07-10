#include<bits/stdc++.h>
int t,n,m;
int p[1010][110];
int f[10010];
int main(){
    std::cin>>t>>n>>m;
    for(int i=1;i<=t;i++){
        for(int j=1;j<=n;j++){
            std::cin>>p[i][j];
        }
    }
    for(int i=2;i<=t;i++){
        memset(f,0,sizeof(f));
        for(int j=1;j<=n;j++){
            for(int k=p[i-1][j];k<=10010;k++){
                f[k]=std::max(f[k],f[k-p[i-1][j]]+p[i][j]-p[i-1][j]);
            }
        }
        m+=f[m];
    }
    std::cout<<m;
    return 0;
}
