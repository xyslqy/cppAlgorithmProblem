#include <bits/stdc++.h>
#define int long long
template <typename T>
inline T read(T& x) {
    x = 0;
    int c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) x = x * 10 - '0' + c, c = getchar();
    return x;
}
template <typename... T, typename type>
inline void read(type& x, T&... y) {
    read(x);
    read(y...);
}
constexpr int maxn = 5e7 + 20, maxm = 5e7 + 20;
int n, m, k, top, ans = 0x3f3f3f3f3f3f3f3f;
int f[maxn], siz[maxn], c[20];
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
inline void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (siz[fx] > siz[fy]) std::swap(fx, fy);
    f[fx] = fy;
    siz[fy]+=siz[fx];
}
struct edge {
    int u, v, w;
} e[maxm];
signed main() {
    read(n, m, k);
    for (int i = 1; i <= m; i++) {
        read(e[i].u, e[i].v, e[i].w);
    }
    top = 0;
    std::sort(e + 1, e + 1 + m, [&](auto x, auto y) { return x.w < y.w; });
    for (int i = 1; i <= n + k; i++) f[i] = i, siz[i] = 1;
    for(int i=1;i<=m;i++){
        if(find(e[i].u)==find(e[i].v))continue;
        merge(e[i].u, e[i].v);
        e[++top]=e[i];
    }
    for (int i = 1; i <= k; i++) {
        read(c[i]);
        for (int j = 1; j <= n; j++) {
            e[++top].u = n + i;
            e[top].v = j;
            read(e[top].w);
        }
    }
    std::sort(e + 1, e + 1 + top, [&](auto x, auto y) { return x.w < y.w; });
    for (int p = 0; p < (1 << k); p++) {
        int cnt = 0;
        for (int i = 1; i <= n + k; i++) f[i] = i, siz[i] = 1;
        for (int i = 1; i <= top; i++) {
            if (e[i].u > n && !((p >> (e[i].u - n - 1)) & 1)) continue;
            if (find(e[i].u) == find(e[i].v)) continue;
            merge(e[i].u, e[i].v);
            cnt += e[i].w;
        }
        for (int i = 0; i < k; i++) {
            if ((p >> i) & 1) cnt += c[i + 1];
        }
        if (ans > cnt) ans = cnt;
    }
    printf("%lld", ans);
    return 0;
}
