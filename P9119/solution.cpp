#include <bits/stdc++.h>
using ld = long double;
constexpr int maxn = 1010;
constexpr ld INF = 1e18;
int n, k;
int p[maxn], g[maxn][maxn][2];
ld px[maxn], py[maxn];
ld f[maxn][maxn][2];
inline ld dis(int x, int y) {
    return std::sqrt((px[p[x]] - px[p[y]]) * (px[p[x]] - px[p[y]]) +
                     (py[p[x]] - py[p[y]]) * (py[p[x]] - py[p[y]]));
}
void answer(int i, int j, int s) {
    if (i < 0 || j > n) return;
    if (s == 0) {
        answer(i - 1, j, g[i][j][s]);
        printf("%d ", p[i]);
    } else {
        answer(i, j + 1, g[i][j][s]);
        printf("%d ", p[j]);
    }
}
int main() {
    std::cin >> n;
    k = 1;
    for (int i = 1; i <= n; i++) {
        std::cin >> px[i] >> py[i];
        if (py[i] > py[k]) k = i;
    }
    for (int i = k; i <= n; i++) p[i - k] = i;
    for (int i = 1; i <= k; i++) p[i + n - k] = i;
    for (int l = 0; l <= n; l++)
        for (int r = l; r <= n; r++) f[l][r][0] = f[l][r][1] = INF;
    f[0][n][0] = f[0][n][1] = 0;
    for (int l = 0; l <= n; l++) {
        for (int r = n; r > l + 1; r--) {
            ld f0 = f[l][r][0] + dis(l + 1, l);
            ld f1 = f[l][r][1] + dis(l + 1, r);
            if (f0 < f1)
                f[l + 1][r][0] = f0;
            else
                f[l + 1][r][0] = f1, g[l + 1][r][0] = 1;
            f0 = f[l][r][0] + dis(r - 1, l);
            f1 = f[l][r][1] + dis(r - 1, r);
            if (f0 < f1)
                f[l][r - 1][1] = f0;
            else
                f[l][r - 1][1] = f1, g[l][r - 1][1] = 1;
        }
    }
    int pos = 0, sta = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 1; j++) {
            if (f[i][i + 1][j] < f[pos][pos + 1][sta]) pos = i, sta = j;
        }
    }
    answer(pos, pos + 1, sta);
    return 0;
}
