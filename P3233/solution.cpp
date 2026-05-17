#include <bits/stdc++.h>
inline int read() {
    int x = 0;
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) {
        x = x * 10 - '0' + c;
        c = getchar();
    }
    return x;
}
const int maxn = 3e5 + 10;
int n, q, tot = 0;
int fa[maxn][30], dfn[maxn], siz[maxn], dep[maxn];
int h[maxn];
int st[maxn], top = 0;
std::vector<int> e[maxn], ie[maxn];
void init(int x) {
    dfn[x] = ++tot;
    dep[x] = dep[fa[x][0]] + 1;
    siz[x] = 1;
    for (int i = 1; i < 30; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
    for (int y : e[x]) {
        if (y == fa[x][0]) continue;
        fa[y][0] = x;
        init(y);
        siz[x] += siz[y];
    }
}
inline int lca(int x, int y) {
    if (dep[x] < dep[y]) std::swap(x, y);
    for (int i = 29; i >= 0; i--) {
        if (dep[fa[x][i]] >= dep[y]) {
            x = fa[x][i];
        }
    }
    if (x == y) return x;
    for (int i = 29; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}
int dp[maxn], g[maxn], ans[maxn];
bool vis[maxn];
void dfs1(int x, int f) {
    dp[x] = 0x3f3f3f3f;
    for (int y : ie[x]) {
        if (y == f) continue;
        dfs1(y, x);
        int dis = dep[y] - dep[x];
        if (dp[y] + dis < dp[x]) dp[x] = dp[y] + dis, g[x] = g[y];
        if (dp[y] + dis == dp[x]) g[x] = std::min(g[x], g[y]);
    }
    if (vis[x]) dp[x] = 0, g[x] = x;
}
inline void cal(int x, int y) {
    int p = y, q = y;
    for (int i = 29; i >= 0; i--) {
        if (dep[fa[p][i]] > dep[x]) {
            p = fa[p][i];
        }
    }
    ans[g[x]] -= siz[p];
    for (int i = 29; i >= 0; i--) {
        int nq = fa[q][i];
        int llen = dp[y] + dep[y] - dep[nq];
        int rlen = dp[x] + dep[nq] - dep[x];
        if (dep[nq] > dep[x] && (llen < rlen || (llen == rlen && g[y] < g[x])))
            q = nq;
    }
    ans[g[y]] += siz[q] - siz[y];
    ans[g[x]] += siz[p] - siz[q];
}
void dfs2(int x, int f) {
    for (int y : ie[x]) {
        if (y == f) continue;
        int dis = dep[y] - dep[x];
        if (dp[x] + dis < dp[y]) dp[y] = dp[x] + dis, g[y] = g[x];
        if (dp[x] + dis == dp[y]) g[y] = std::min(g[x], g[y]);
        cal(x, y);
        dfs2(y, x);
    }
    ans[g[x]] += siz[x];
    vis[x] = 0;
    ie[x].clear();
}
int tmp[maxn];
int main() {
    n = read();
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    init(1);
    q = read();
    while (q--) {
        int m = read();
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= m; i++) {
            tmp[i] = h[i] = read();
            ans[h[i]] = 0;
            vis[h[i]] = true;
        }
        bool flag = false;
        if (!vis[1]) flag = true, h[++m] = 1;
        std::sort(h + 1, h + 1 + m,
                  [&](int x, int y) { return dfn[x] < dfn[y]; });
        st[top = 1] = 1;
        for (int i = 2; i <= m; i++) {
            int lc = lca(st[top], h[i]);
            while (dep[lc] < dep[st[top - 1]]) {
                ie[st[top - 1]].push_back(st[top]);
                top--;
            }
            if (dep[lc] < dep[st[top]]) ie[lc].push_back(st[top]), top--;
            if (st[top] != lc) st[++top] = lc;
            st[++top] = h[i];
        }
        while (--top) ie[st[top]].push_back(st[top + 1]);
        dfs1(1, 0);
        dfs2(1, 0);
        if (flag) m--;
        for (int i = 1; i <= m; i++) {
            printf("%d ", ans[tmp[i]]);
        }
        puts("");
    }
    return 0;
}
