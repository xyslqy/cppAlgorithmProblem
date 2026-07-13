#include <bits/stdc++.h>
using ll = long long;
using pii = std::pair<int, int>;
using plii = std::pair<ll, pii>;
constexpr int maxn = 3e5 + 10;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
int n, m, k;
int d[maxn];
ll v[maxn], w[maxn];
std::vector<ll> dis[maxn];
std::vector<bool> vis[maxn];
std::vector<pii> to[maxn];
std::priority_queue<plii, std::vector<plii>, std::greater<plii>> pq;
int main() {
    int c;
    std::cin >> c >> n >> m >> k;
    for (int i = 1; i < k; i++) std::cin >> v[i], v[i] += v[i - 1];
    for (int i = 2; i <= k; i++) std::cin >> w[i], w[i] += w[i - 1];
    for (int i = 1; i <= n; i++) {
        std::cin >> d[i];
        dis[i].assign(d[i] + 1, INF);
        vis[i].assign(d[i] + 1, 0);
        to[i].assign(d[i] + 1, {0, 0});
        for (int j = 1; j <= d[i]; j++) {
            int y, z;
            std::cin >> y >> z;
            to[i][j] = {y, z};
        }
    }
    for (int i = 1; i <= d[1]; i++) {
        pq.push({dis[1][i] = v[i - 1], {1, i}});
    }
    while (!pq.empty()) {
        auto pos = pq.top().second;
        pq.pop();
        int x = pos.first, p = pos.second;
        if (vis[x][p]) continue;
        vis[x][p] = 1;
        int i = p;
        int y = to[x][i].first;
        ll ww = to[x][i].second;
        for (int yp = 1; yp <= d[y]; yp++) {
            ll t = ww + dis[x][p];
            if (yp > p) {
                t += v[yp - 1] - v[p - 1];
            } else if (yp < p) {
                t += w[p] - w[yp];
            }
            if (t < dis[y][yp]) {
                dis[y][yp] = t;
                pq.push({t, {y, yp}});
            }
        }
        if (ww + dis[x][p] < dis[y][0]) {
            dis[y][0] = ww + dis[x][p];
        }
    }
    for (int i = 1; i <= n; i++) {
        ll min = INF;
        for (int p = 0; p <= d[i]; p++) {
            min = std::min(min, dis[i][p]);
        }
        if (min == INF)
            std::cout << "-1 ";
        else
            std::cout << min << " ";
    }
    return 0;
}
