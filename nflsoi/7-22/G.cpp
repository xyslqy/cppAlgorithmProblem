#include <bits/stdc++.h>
#define int long long
constexpr int maxn = 2e5 + 10, mod = 1e9 + 7;
int n;
int f[maxn], g[maxn];
int ans;
std::vector<int> to[maxn];
void dfs(int x, int fa) {
    f[x] = 1;
    for (int y : to[x]) {
        if (y == fa) continue;
        dfs(y, x);
        f[x] = 1ll * f[x] * (f[y] + 1) % mod;
    }
}
void Dfs(int x, int fa, int v) {
    g[x] = 1ll * f[x] * (v + 1) % mod;
    std::vector<int> chd;
    for (int y : to[x]) {
        if (y != fa) chd.push_back(y);
    }
    int siz = chd.size();
    std::vector<int> sa(siz + 2, 1), sb(siz + 2, 1);
    for (int i = 0; i < siz; i++)
        sa[i + 1] = 1ll * sa[i] * (f[chd[i]] + 1) % mod;
    for (int i = siz - 2; i >= 0; i--)
        sb[i] = 1ll * sb[i + 1] * (f[chd[i + 1]] + 1) % mod;
    for (int i = 0; i < siz; i++) {
        int y = chd[i];
        if (y == fa) continue;
        Dfs(y, x, 1ll * sa[i] * sb[i] % mod * (v + 1) % mod);
    }
}
signed main() {
    std::cin >> n;
    for (int i = 2; i <= n; i++) {
        int j;
        std::cin >> j;
        to[j].push_back(i);
        to[i].push_back(j);
    }
    dfs(1, 0);
    Dfs(1, 0, 0);
    for (int i = 1; i <= n; i++) {
        std::cout << g[i] << " ";
    }
    return 0;
}
