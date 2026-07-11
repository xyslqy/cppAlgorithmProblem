#include <bits/stdc++.h>
using ll = long long;
constexpr int mod = 1e9 + 7;
int n, k;
char c[510];
ll f[510][510][6];
int s[510];
int main() {
    std::cin >> n >> k >> (c + 1);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + (c[i] == '(' || c[i] == ')'), f[i][i - 1][0] = 1;
    for (int len = 1; len <= n; len++) {
        for (int l = 1; l <= n - len + 1; l++) {
            int r = l + len - 1;
            if (s[r] - s[l - 1] == 0 && len <= k) f[l][r][0] = 1;
            if (len >= 2) {
                if (c[l] != ')' && c[l] != '*' && c[r] != '(' && c[r] != '*')
                    f[l][r][1] = (f[l + 1][r - 1][0] + f[l + 1][r - 1][2] +
                                  f[l + 1][r - 1][3] + f[l + 1][r - 1][4]) %
                                 mod;
                for (int i = l; i <= r - 1; i++) {
                    f[l][r][2] =
                        (f[l][r][2] + f[l][i][3] * f[i + 1][r][0]) % mod;
                    f[l][r][3] = (f[l][r][3] +
                                  (f[l][i][2] + f[l][i][3]) * f[i + 1][r][1]) %
                                 mod;
                    f[l][r][4] = (f[l][r][4] +
                                  (f[l][i][4] + f[l][i][5]) * f[i + 1][r][1]) %
                                 mod;
                    f[l][r][5] =
                        (f[l][r][5] + f[l][i][4] * f[i + 1][r][0]) % mod;
                }
            }
            f[l][r][3] = (f[l][r][3] + f[l][r][1]) % mod;
            f[l][r][5] = (f[l][r][5] + f[l][r][0]) % mod;
        }
    }
    printf("%lld", f[1][n][3]);
    return 0;
}
