#include <bits/stdc++.h>
typedef long long ll;
const int maxn = 1e6 + 10;
int n;
ll ans, cnt, s[maxn];
ll read() {
    ll x = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 - '0' + c;
        c = getchar();
    }
    return x;
}
ll inline labs(ll x) { return x > 0 ? x : -x; }
ll calc(int l, int r, int k) {
    if (l >= r) return s[l];
    int i = l - 1, j = l;
    for (; j <= r; j++) {
        if (s[j] <= s[r]) {
            std::swap(s[++i], s[j]);
        }
    }
    if (k == i - l + 1)
        return s[i];
    else if (k <= i - l) {
        return calc(l, i - 1, k);
    } else {
        return calc(i + 1, r, k - i + l - 1);
    }
}
int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        s[i] = read();
        cnt += s[i];
    }
    cnt /= n;
    for (int i = 1; i <= n; i++) {
        s[i] = s[i] - cnt + s[i - 1];
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(s+1,s+1+n,g);
    int k = calc(1, n, (n + 1) >> 1);
    for (int i = 1; i <= n; i++) {
        ans += labs(s[i] - k);
    }
    printf("%lld", ans);
    return 0;
}
