#include <bits/stdc++.h>
#define ll long long
constexpr int maxn = 2e6 + 10;
template <typename T>
inline T read(T& x) {
    x = 0;
    int c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) x = x * 10 - '0' + c, c = getchar();
    return x;
}
template <typename T>
inline void ckmax(T& x, T y) {
    if (y > x) x = y;
}
int t, n;
int a[maxn], lst[maxn];
ll f[maxn], s[maxn];
inline void solve() {
    read(n);
    for (int i = 1; i <= n; i++) {
        read(a[i]);
        s[i] = s[i - 1];
        if (a[i] == a[i - 1]) s[i] += a[i];
    }
    memset(f, 0, sizeof(f));
    memset(lst, 0, sizeof(lst));
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1];
        if (lst[a[i]])
            ckmax(f[i], f[lst[a[i]] + 1] + a[i] + s[i] - s[lst[a[i]] + 1]);
        lst[a[i]] = i;
    }
    printf("%lld\n", f[n]);
}
int main() {
    read(t);
    while (t--) {
        solve();
    }
    return 0;
}
