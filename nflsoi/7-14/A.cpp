#include <bits/stdc++.h>
constexpr double INF = 1e18;
int n, m;
int x[21], y[21];
double f[1 << 21][21], v[20], dist[21][21];
double dis(double x, double y, double p, double q) {
    return std::sqrt((x - p) * (x - p) + (y - q) * (y - q));
}
int main() {
    // freopen("visit.in", "r", stdin);
    // freopen("visit.out", "w", stdout);
    std::cin >> n >> m;
    v[0] = 1;
    for (int i = 1; i <= m; i++) {
        v[i] = v[i - 1] / 2;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> x[i + m] >> y[i + m];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> x[i] >> y[i];
    }
    memset(f, 0x7f, sizeof(f));
    for (int i = 0; i < n + m; i++) {
        f[1 << i][i] = dis(x[i], y[i], 0, 0);
    }
    for (int mask = 0; mask < (1 << (n + m)); mask++) {
        double v0 = v[__builtin_popcount(mask & ((1 << m) - 1))];
        for (int u = 0; u < n + m; u++) {
            if (mask & (1 << u)) continue;
            for (int v = 0; v < n + m; v++) {
                if (!(mask & (1 << v))) continue;
                f[mask | (1 << u)][u] =
                    std::min(f[mask | (1 << u)][u],
                             f[mask][v] + dis(x[u], y[u], x[v], y[v]) * v0);
            }
        }
    }
    int t = ((1 << n) - 1) << m;
    double ans = INF;
    for (int mask = 0; mask < (1 << (n + m)); mask++) {
        if ((mask & t) == t)
            for (int u = 0; u < n + m; u++)
                ans = std::min(
                    ans, f[mask][u] +
                             dis(x[u], y[u], 0, 0) *
                                 v[__builtin_popcount(mask & ((1 << m) - 1))]);
    }
    printf("%.10f", ans);

    return 0;
}
