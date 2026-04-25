#include <bits/stdc++.h>
int inline read() {
    int x = 0;

    char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}
const int maxn = 1e5 + 10;
int n, k;
int c[maxn];
int fa[maxn];
int f[maxn][30];
std::vector<int> e[maxn];
void dfs(int x) {
    for (int i = 0; i <= k; i++) f[x][i] = c[x];
    for (int y : e[x]) {
        if (y == fa[x]) continue;
        fa[y] = x;
        dfs(y);
        for (int i = 1; i <= k; i++) {
            f[x][i] += f[y][i - 1];
        }
    }
}
int query(int x, int sf, int kk) {
    if (kk < 0 || !x) return 0;
    return (f[x][kk]) - ((kk > 0) ? (f[sf][kk - 1]) : 0) +
           query(fa[x], x, kk - 1);
}
int main() {
    n = read();
    k = read();
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        c[i] = read();
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        printf("%d\n", query(i, 0, k));
    }
    return 0;
}
