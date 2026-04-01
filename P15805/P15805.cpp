#include <bits/stdc++.h>
using namespace std;
const int maxn = 105, mod = 1e9;
int n, m, ans;
int f[maxn][maxn];
int g[maxn][maxn];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (g[u][v] > w || !g[u][v]) {
            g[u][v] = w;
            g[v][u] = w;
        }
    }
    for (int l = 1; l <= n; l++) {
        for (int i = l; i <= n; i++) {
            for (int j = l; j <= n; j++) {
                f[i][j] = g[i][j];
            }
        }
        for (int r = l; r <= n; r++) {
            for (int k = l; k <= r; k++) {
                for (int i = l; i <= r; i++) {
                    for (int j = l; j <= r; j++) {
                        if (i == j) continue;
                        if (f[i][k] && f[k][j] &&
                            (f[i][k] + f[k][j] < f[i][j] || !f[i][j])) {
                            f[i][j] = f[i][k] + f[k][j];
                        }
                    }
                }
            }
            for (int i = l; i <= r; i++) {
                for (int j = i + 1; j <= r; j++) {
                    ans = (ans + f[i][j]) % mod;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
