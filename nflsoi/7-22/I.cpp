#include <bits/stdc++.h>
constexpr int maxn = 2010;
int n;
int a[maxn];
long long f[maxn][maxn];
int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    std::sort(a + 1, a + 1 + n);
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l <= n - len + 1; l++) {
            int r = l + len - 1;
            f[l][r] = std::min(f[l][r - 1], f[l + 1][r]) + a[r] - a[l];
        }
    }
    std::cout << f[1][n];
    return 0;
}
