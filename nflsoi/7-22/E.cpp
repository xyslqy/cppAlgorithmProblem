#include <bits/stdc++.h>
using ull = unsigned long long;
constexpr int maxn = 50010;
int n, k;
ull f[maxn][510], ans;
std::vector<int> to[maxn];
void dfs(int x, int fa) {
    f[x][0] = 1;
    for (int y : to[x]) {
        if (y == fa) continue;
        dfs(y, x);
        for (int i = 0; i < k; i++) {
            ans += f[x][k - i - 1] * f[y][i];
        }
        for (int i = 1; i <= k; i++) {
            f[x][i] += f[y][i - 1];
        }
    }
}
int main() {
    std::cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    dfs(1, 0);
    std::cout << ans;
    return 0;
}
