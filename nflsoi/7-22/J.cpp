#include <bits/stdc++.h>
constexpr int maxn = 505;
int n;
char c[maxn];
int f[maxn][maxn][2];
inline void ckmin(int& x, int y) {
    if (x > y) x = y;
}
int main() {
    std::cin >> n >> (c + 1);
    for (int i = 1; i <= n; i++) f[i][i][0] = 1;
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l <= n - len + 1; l++) {
            int r = l + len - 1;
            f[l][r][1] = (f[l][r][0] = len) + 1;
            for (int k = l; k < r; k++) {
                if (c[l] == c[k + 1]) {
                    ckmin(f[l][r][1], f[l][k][1] + f[k + 1][r][1]);
                    ckmin(f[l][r][0], f[l][k][1] + f[k + 1][r][1] + 1);
                } else {
                    ckmin(f[l][r][1], f[l][k][1] + f[k + 1][r][0]);
                    ckmin(f[l][r][0], f[l][k][0] + f[k + 1][r][0]);
                }
            }
        }
    }
    std::cout << f[1][n][0];
    return 0;
}
// f[l][r][0/1] 把lr删到只剩首字符或全部删完
