#include <bits/stdc++.h>
#define For(i, st, ed) for (int i = (st); i <= (ed); i++)
using ll = long long;
template <typename T>
inline T read(T& x) {
    x = 0;
    int c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) x = x * 10 - '0' + c, c = getchar();
    return x;
}
template <typename type, typename... T>
inline void read(type& x, T&... y) {
    read(x);
    read(y...);
}
inline constexpr int maxn = 1e5 + 10, mod = 998244353;
int n, m;
int pos[maxn];
bool tp[maxn];
ll a[maxn], mul[maxn], v[maxn],cnt[maxn];
std::vector<int> G1[maxn], G2[maxn];
bool vis[maxn];
ll cal_mul(int x) {
    if (vis[x]) return mul[x];
    for (int y : G2[x]) {
        mul[x] = (mul[x] * cal_mul(y)) % mod;
    }
    vis[x] = 1;
    return mul[x];
}
int deg[maxn];
void tttt() {
    static std::queue<int> q;
    For(i, 0, m) if (!(deg[i] = G1[i].size())) q.push(i);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        ll now_mul = 1;
        for (int i = G2[x].size() - 1; i >= 0; i--) {
            int y = G2[x][i];
            cnt[y] = (cnt[y] + cnt[x] * now_mul) % mod;
            now_mul = (now_mul * mul[y]) % mod;
            deg[y]--;
            if (!deg[y]) q.push(y);
        }
    }
}
int main() {
    read(n);
    For(i, 1, n) read(a[i]);
    read(m);
    For(i, 1, m) {
        int t = read(t);
        if (t == 1) {
            read(pos[i], v[i]);
            mul[i] = 1;
            tp[i] = 1;
        } else if (t == 2) {
            read(mul[i]);
        } else {
            mul[i] = 1;
            int c = read(c);
            For(j, 1, c) {
                int v = read(v);
                G1[v].push_back(i);
                G2[i].push_back(v);
            }
        }
    }
    int Q = read(Q);
    mul[0] = 1;
    cnt[0] = 1;
    while (Q--) {
        int v = read(v);
        G1[v].push_back(0);
        G2[0].push_back(v);
    }
    cal_mul(0);
    tttt();
    For(i, 1, n) a[i] = (a[i] * mul[0]) % mod;
    For(i, 1, m) {
        if (tp[i]) a[pos[i]] = (a[pos[i]] + v[i] * cnt[i] % mod) % mod;
    }
    For(i, 1, n) printf("%lld ", a[i]);
    return 0;
}
