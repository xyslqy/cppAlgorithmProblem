#include <bits/stdc++.h>

#include <cstdio>
inline int read() {
    int x = 0, c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) {
        x = x * 10 - '0' + c;
        c = getchar();
    }
    return x;
}
typedef long long ll;
const int N = 1e5 + 10, mod = 1e9 + 7;
ll inv[N], sum[N][2], ans;
int n, k;
int u[N], v[N], d[N];
bool flag[N];
std::vector<std::pair<int, bool>> to[N];
void dfs(int x, int fa) {
    sum[x][0] = sum[x][1] = 0;
    ll val = 0;
    for (auto _ : to[x]) {
        int y = _.first;
        if (y == fa) continue;
        dfs(y, x);
        if (_.second) {
            (sum[y][1] += sum[y][0]) %= mod;
            sum[y][0] = 0;
        }
        (val += sum[y][1] * (sum[x][0] + sum[x][1]) + sum[y][0] * sum[x][1]) %=
            mod;
        (sum[x][0] += sum[y][0]) %= mod;
        (sum[x][1] += sum[y][1]) %= mod;
    }
    ll INV = inv[d[x]];
    (ans += val * INV) %= mod;
    if (!d[x]) sum[x][0]++;
    (sum[x][0] *= INV) %= mod;
    (sum[x][1] *= INV) %= mod;
    return;
}
void solve() {
    n = read();
    k = read();
    for (int i = 1; i <= n; i++) {
        to[i].clear();
        d[i] = -1;
        flag[i] = 0;
    }
    for (int i = 1; i < n; i++) {
        d[u[i] = read()]++;
        d[v[i] = read()]++;
    }
    for (int i = 1; i <= k; i++) {
        flag[read()] = true;
    }
    for (int i = 1; i < n; i++) {
        to[u[i]].push_back({v[i], flag[i]});
        to[v[i]].push_back({u[i], flag[i]});
    }
    if (n == 2) {
        printf("1\n");
        return;
    }
    ans = 0;
    int rt = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i]) {
            rt = i;
            break;
        }
    }
    dfs(rt, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= d[i]; j++) {
            (ans *= j) %= mod;
        }
    }
    printf("%lld\n", ans);
    return;
}
int main() {
    inv[0] = inv[1] = 1;
    for (int i = 2; i < N; i++) {
        inv[i] = (ll)(mod - mod / i) * inv[mod % i] % mod;
    }
    int c = read(), t = read();
    while (t--) {
        solve();
    }
    return 0;
}
