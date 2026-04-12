#include <bits/stdc++.h>
typedef long long ll;
int inline read() {
    int x = 0;
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) {
        x = x * 10 - '0' + c;
        c = getchar();
    }
    return x;
}
const int maxn = 1 << 12, inf = 0x3f3f3f3f;
int n, m;
int f[maxn][maxn];
int L[maxn][maxn];
int e[13][13];
bool in(int a, int i) { return (a >> i) & 1; };
int calc(int a, int b) {
    int lenth[13];
    memset(lenth, 0x3f, sizeof(lenth));
    for (int i = 0; i < n; i++) {
        if (!in(a, i)) continue;
        for (int j = 0; j < n; j++) {
            if (!in(b, j)) continue;
            lenth[i] = std::min(e[i + 1][j + 1], lenth[i]);
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (in(a, i) && !in(b, i)) res = std::min(res + lenth[i], inf);
    }
    return res;
}
signed main() {
    n = read();
    m = read();
    memset(L, 0x3f,sizeof(L));
    memset(f, 0x3f, sizeof(f));
    memset(e, 0x3f, sizeof(e));
    for (int i = 0; i < n; i++) {
        f[0][1 << i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read(), w = read();
        if(e[u][v]<w) continue;
        e[u][v] = w;
        e[v][u] = w;
    }
    for(int i=0;i<(1<<n);i++){
        for(int j=i;j>0;j=(j-1)&i){
            L[i][j]=calc(i,j);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < (1 << n); j++) {
            for (int k = j; k > 0; k = (k - 1) & j) {
                if(L[j][k]==inf) continue;
                f[i][j] = std::min(f[i][j], f[i - 1][k] + L[j][k] * i);
            }
        }
    }
    int ans = inf;
    for (int i = 1; i <= n; i++) {
        std::cerr<<f[i][(1<<n)-1]<<"\n";
        ans = std::min(ans, f[i][(1 << n) - 1]);
    }
    printf("%d", ans);
    return 0;
}
