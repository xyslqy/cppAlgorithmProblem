#include <bits/stdc++.h>
int read() {
    int x = 0;
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}
const int maxn = 1e5 + 10, mod = 1e9 + 7;
int n, k;
int f[maxn][4];
int b[maxn];
std::vector<int> e[maxn];
void dfs(int x, int fa) {
    if (b[x])
        f[x][b[x]] = 1;
    else
        f[x][1] = f[x][2] = f[x][3] = 1;
    for (int y : e[x]) {
        if (y == fa) continue;
        dfs(y, x);
        f[x][1] = 1ll * f[x][1] * ((f[y][2] + f[y][3]) % mod) % mod;
        f[x][2] = 1ll * f[x][2] * ((f[y][1] + f[y][3]) % mod) % mod;
        f[x][3] = 1ll * f[x][3] * ((f[y][2] + f[y][1]) % mod) % mod;
    }
}
int main() {
    n = read();
    k = read();
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= k; i++) {
        int x = read(), y = read();
        b[x] = y;
    }
    dfs(1, 0);
    printf("%d", ((f[1][1] + f[1][2]) % mod + f[1][3]) % mod);
    return 0;
}
