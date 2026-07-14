#include <bits/stdc++.h>
constexpr int maxn = 1e6 + 10, siz = 23, full = (1 << siz) - 1;
constexpr int mod = 1e9 + 7;
int n;
int a[maxn], f[full + 1];
int pow2[maxn];
int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        f[a[i]]++;
    }
    for (int bit = 0; bit < siz; bit++) {
        for (int mask = 0; mask <= full; mask++) {
            if (mask >> bit & 1) continue;
            f[mask] = (f[mask] + f[mask ^ (1 << bit)]) % mod;
        }
    }
    pow2[0] = 1;
    for (int i = 1; i <= n; i++) pow2[i] = pow2[i - 1] * 2 % mod;
    int ans = 0;
    for (int mask = 0; mask <= full; mask++) {
        if (__builtin_popcount(mask) % 2 == 1)
            ans = (ans + mod - pow2[f[mask]] + 1) % mod;
        else
            ans = (ans + pow2[f[mask]] - 1) % mod;
    }
    std::cout << ans;
    return 0;
}
