#include <bits/stdc++.h>
const int maxn = 1e5 + 10;
int inline read() {
    int x = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 - '0' + c;
        c = getchar();
    }
    return x;
}
int n, ans;
int s[maxn];
std::vector<std::pair<int, int>> e[maxn];
struct node {
    int next[2];
};
node t[32 * maxn];
int tot=1;
void insert(int x) {
    int p = 1;
    for (int i = 30; i >= 0; i--) {
        int now = (x >> i) & 1;
        if (t[p].next[now])
            p = t[p].next[now];
        else {
            t[p].next[now] = ++tot;
            p = tot;
        }
    }
}
void dfs(int x, int f, int val) {
    for (auto _ : e[x]) {
        int y = _.first, w = _.second;
        if (y != f) {
            insert(w ^ val);
            s[y] = w ^ val;
            dfs(y, x, w ^ val);
        }
    }
}
int query(int x) {
    int res = 0, p = 1;
    for (int i = 30; i >= 0; i--) {
        int now = (x >> i) & 1;
        if (t[p].next[now ^ 1]) {
            p = t[p].next[now ^ 1];
            res ^= (1 << i);
        } else {
            p = t[p].next[now];
        }
    }
    return res;
}
int inline max(int x, int y) { return x > y ? x : y; }
signed main() {
    n = read();
    for (int i = 1; i < n; i++) {
        int u = read(), v = read(), w = read();
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    insert(0);
    dfs(1, 0, 0);
    for (int i = 1; i <= n; i++) {
        ans = max(ans, query(s[i]));
    }
    printf("%d", ans);
    return 0;
}
