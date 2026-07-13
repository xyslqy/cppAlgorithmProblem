#include <bits/stdc++.h>
#define int long long
constexpr int maxn = 1e4 + 10;
int n, m, k;
int dis[maxn][110];
bool vis[maxn][110];
std::vector<std::pair<int, int>> to[maxn];
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                    std::greater<std::pair<int, int>>>
    pq;
inline void dij() {
    memset(dis, 0x3f, sizeof(dis));
    dis[1][0] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        int x = pq.top().second, p = pq.top().first;
        pq.pop();
        if (vis[x][p % k]) continue;
        vis[x][p % k] = true;
        for (auto d : to[x]) {
            int w = d.first, y = d.second;
            int t;
            if (p >= w)
                t = p;
            else
                t = ((w - p + k - 1) / k) * k + p;
            if (dis[y][(t + 1) % k] > t + 1) {
                dis[y][(t + 1) % k] = t + 1;
                pq.push({t + 1, y});
            }
        }
    }
}
signed main() {
    std::cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        to[u].push_back({w, v});
    }
    dij();
    if (!vis[n][0])
        puts("-1");
    else
        std::cout << dis[n][0];
    return 0;
}
