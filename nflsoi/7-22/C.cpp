#include <bits/stdc++.h>
constexpr int maxn = 1e6 + 10, siz = 22, full = (1 << siz) - 1;
int n;
int f[full + 1], a[maxn];
int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        f[a[i]] = a[i];
    }
    for (int bit = 0; bit < siz; bit++) {
        for (int mask = 1; mask <= full; mask++) {
            if (!((mask >> bit) & 1)) continue;
            if (!f[mask]) {
                f[mask] = f[mask ^ (1 << bit)];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int t=f[full&(~a[i])];
        if (!t) std::cout << "-1 ";
        else std::cout << t << " ";
    }
    return 0;
}
