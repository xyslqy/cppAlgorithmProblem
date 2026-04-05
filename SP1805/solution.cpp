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
const int maxn = 1e6 + 10;
int n, h, tot;
ll ans;
ll sh[maxn], sw[maxn];
ll max(ll x, ll y) { return x > y ? x : y; }
void solve() {
    ans = 0;
    while (n--) {
        h = read();
        if (h > sh[tot]) {
            sh[++tot] = h;
            sw[tot] = 1;
        } else {
            int w = 0;
            while (sh[tot] > h) {
                w += sw[tot];
                ans = max(ans, (ll)w * sh[tot]);
                tot--;
            }
            sh[++tot] = h;
            sw[tot] = w + 1;
        }
    }
    int w = 0;
    while (tot) {
        w += sw[tot];
        ans = max(ans, (ll)w * sh[tot]);
        tot--;
    }
    printf("%lld\n", ans);
}

int main() {
    while (true) {
        n = read();
        if (n == 0) break;
        solve();
    }
    return 0;
}
