#include <bits/stdc++.h>
const int maxn = 1e5 + 10, INF = 0x3f3f3f3f;
int n, q, r;
int f[maxn];
int b[maxn], tot = 0;  // 存储要进行dp的节点
std::vector<int> G[maxn];
int inline min(int x, int y) { return x < y ? x : y; }
int main() {
    std::cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        std::cin >> r;
        if (r) {
            G[r].push_back(i);
            b[++tot] = i;
            b[++tot] = r;
        }
    }
    // 去重
    std::sort(b + 1, b + 1 + tot);
    tot = std::unique(b + 1, b + 1 + tot) - b - 1;

    while (q--) {
        int x, y;
        std::cin >> x >> y;
        memset(f, 0x3f,sizeof(f));
        f[x] = 0;
        f[y] = x - y;
        int i;
        for (i = tot; i >= 1; i--) {
            if (b[i] > x) continue;
            if (b[i] < y) break;
            int now = b[i];
            int pre = b[i + 1];
            f[now] = min(f[pre] + pre - now, x - now);  // 通过主链更新f[now]
            for (int v : G[now]) {
                f[now] = min(f[v] + 1, f[now]);  // 枚举r^{-1}[now]，更新f[now]
            }
        }
        // y不一定在数组b中，因此需要单独更新一下
        int pre = b[i + 1];
        f[y] = min(f[pre] + pre - y, f[y]);
        std::cout << f[y] << "\n";
    }
    return 0;
}
