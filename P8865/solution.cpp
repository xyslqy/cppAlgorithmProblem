#include <bits/stdc++.h>
constexpr int mod = 998244353, maxn = 1010;
int n, m, C, F;
int f[maxn][maxn];
char s[maxn][maxn];
inline void solve() {
    std::cin >> n >> m >> C >> F;
    for (int i = 1; i <= n; i++) {
        std::cin >> (s[i] + 1);
    }
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            if (s[i][j] == '1')
                f[i][j] = -1;
            else if (j < m)
                f[i][j] = f[i][j + 1] + 1;
        }
    }
    int ansc = 0, ansf = 0;
    for (int j = 1; j <= m - 1; j++) {
        int crowsb = 0;
        int numc = 0;
        for (int i = 1; i <= n; i++) {
            if (f[i][j] == -1) {
                crowsb = 0;
                numc = 0;
                continue;
            }
            ansf = (ansf + numc) % mod;
            numc = (numc + 1ll * crowsb * f[i][j] % mod) % mod;
            ansc = (ansc + 1ll * crowsb * f[i][j] % mod) % mod;
            crowsb = (crowsb + std::max(0, f[i - 1][j])) % mod;
        }
    }
    printf("%d %d\n", ansc * C, ansf * F);
}
int main() {
    int T, id;
    std::cin >> T >> id;
    while (T--) {
        solve();
    }
    return 0;
}
