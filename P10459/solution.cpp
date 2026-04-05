#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
int read() {
    int x = 0;
    char c = getchar();
    while (c < '0' || c > '9') {
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 - '0' + c;
        c = getchar();
    }
    return x;
}
typedef long long ll;
const int maxn = 2e5 + 10;
int t, n;
ll mindist;
struct point {
    bool type;
    ll x, y;
};
point p[maxn];
ll inline abs(ll x) { return x * x; }
ll inline dis(point x, point y) {
    return (x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y);
}
void solve(int l, int r) {
    if (l >= r) return;
    int mid = (l + r) >> 1;
    int midx = p[mid].x;
    solve(l, mid);
    solve(mid + 1, r);
    std::inplace_merge(p + l, p + mid + 1, p + r + 1,
                       [&](point x, point y) { return x.y < y.y; });
    std::vector<point> t;
    for (int i = l; i <= r; i++) {
        if (abs(p[i].x - midx) < mindist) {
            t.push_back(p[i]);
        }
    }
    int tsize = t.size();
    for (int i = 0; i < tsize; i++) {
        for (int j = i + 1; j < tsize; j++) {
            if (abs(t[i].y - t[j].y) >= mindist) break;
            if (t[i].type == t[j].type) continue;
            ll dist = dis(t[i], t[j]);
            if (dist < mindist) {
                mindist = dist;
            }
        }
    }
}
int main() {
    t = read();
    while (t--) {
        n = read();
        for (int i = 1; i <= n; i++) {
            int x = read(), y = read();
            p[i].x = x;
            p[i].y = y;
            p[i].type = 0;
        }
        for (int i = n + 1; i <= (n << 1); i++) {
            int x = read(), y = read();
            p[i].x = x;
            p[i].y = y;
            p[i].type = 1;
        }
        mindist = 0x3f3f3f3f3f3f3f3f;

        std::sort(p + 1, p + 1 + n + n,
                  [&](point x, point y) { return x.x < y.x; });
        solve(1, 2 * n);
        printf("%.3Lf\n", sqrtl(mindist));
    }
    return 0;
}
