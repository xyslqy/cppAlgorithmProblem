#include <bits/stdc++.h>
typedef long long ll;
int inline read() {
    int x = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 - '0' + c;
        c = getchar();
    }
    return x;
}
const int maxn = 1e5 + 10;
int n, m, a, b, c[maxn];
ll ans, dis[maxn];
bool vis[maxn];
std::vector<std::pair<int, int>> e[maxn];
struct node {
    ll dis;
    int id;
    bool operator<(const node& x) const { return dis > x.dis; }
};
std::priority_queue<node> pq;
int main() {
    n = read();
    m = read();
    a = read();
    b = read();
    for (int i = 1; i <= n; i++) c[i] = read();
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read(), w = read();
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[b] = 0;
    pq.push({0, b});
    while (!pq.empty()) {
        int x = pq.top().id;
        pq.pop();
        if (vis[x]) continue;
        vis[x] = true;
        for (auto _ : e[x]) {
            int y = _.first, w = _.second;
            if (dis[y] > dis[x] + w) {
                dis[y] = dis[x] + w;
                pq.push({dis[y], y});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dis[i] < dis[a]) ans += c[i];
    }
    printf("%lld", ans);
    return 0;
}
