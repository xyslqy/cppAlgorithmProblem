#include <bits/stdc++.h>
constexpr int maxn = 1e5 + 10, mod = 1e9 + 7;
int n;
int f[maxn][2];
bool sign[maxn];
std::vector<int> to[maxn];
void dfs(int x, int fa) {
    f[x][sign[x]] = 1;
    for (int y : to[x]) {
        if (y == fa) continue;
        dfs(y, x);
        int sum = (f[y][0] + f[y][1]) % mod;
        f[x][1] =
            ((1ll * f[x][1] * sum % mod) + (1ll * f[x][0] * f[y][1] % mod)) %
            mod;
        f[x][0] = 1ll * f[x][0] * sum % mod;
    }
}
int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) std::cin >> sign[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    dfs(1, 0);
    std::cout << f[1][1];
    return 0;
}
