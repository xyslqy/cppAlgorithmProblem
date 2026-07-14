#include <bits/stdc++.h>
const int maxn = 2e6 + 10;
int n, ans;
int f[maxn],g[maxn];
char c[maxn];
int main() {
    std::cin >> n >> (c + 1);
    for (int i = 1; i <= n; i++) {
        g[i]=i-1;
        while(g[i]>0&&c[g[i]]!=c[i]) g[i]=g[g[i]]-1;
        if(g[i]>0) ans+=f[i]=f[g[i]-1]+1;
    }
    std::cout << ans;
    return 0;
}
