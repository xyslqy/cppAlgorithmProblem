#include <bits/stdc++.h>
int n;
char G[17][17];
bool f[1 << 17][6][6][6];
void solve() {
    memset(f, 0, sizeof(f));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%s", &G[i]);
    for (int i = 0; i < n; i++) f[1 << i][0][0][0] = 1;
    for (int mask = 1; mask < (1 << n); mask++) {
        int t = __builtin_popcount(mask) - 1;
        for (int u = 0; u < n; u++) {
            if ((mask >> u) & 1) continue;
            int nm = mask | (1 << u);
            for (int v = 0; v < n; v++) {
                if (!((mask >> v) & 1)) continue;
                if (G[u][v] == '.') continue;
                char w = G[u][v];
                int b;
                if (w == 'R') {
                    for (int r = 0; r < (n - 1) / 3; r++)
                        for (int g = 0; g <= (n - 1) / 3; g++) {
                            b = t - r - g;
                            if (b < 0 || b > (n - 1) / 3) continue;
                            f[nm][r + 1][g][b] |= f[mask][r][g][b];
                        }
                } else if (w == 'G') {
                    for (int g = 0; g < (n - 1) / 3; g++)
                        for (int r = 0; r <= (n - 1) / 3; r++) {
                            b = t - r - g;
                            if (b < 0 || b > (n - 1) / 3) continue;
                            f[nm][r][g + 1][b] |= f[mask][r][g][b];
                        }
                } else if (w == 'B') {
                    for (int r = 0; r <= (n - 1) / 3; r++)
                        for (int g = 0; g <= (n - 1) / 3; g++) {
                            b = t - r - g;
                            if (b < 0 || b >= (n - 1) / 3) continue;
                            f[nm][r][g][b + 1] |= f[mask][r][g][b];
                        }
                }
            }
        }
    }
    if (f[(1 << n) - 1][(n - 1) / 3][(n - 1) / 3][(n - 1) / 3])
        puts("Exist");
    else
        puts("Does not exist");
}
int main() {
    // freopen("three.in", "r", stdin);
    // freopen("three.out", "w", stdout);
    int T;
    std::cin >> T;
    while (T--) solve();
}
