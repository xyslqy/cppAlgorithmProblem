#include <bits/stdc++.h>
#define ll long long
int n;
int sx, sy;
int x[25], y[25];
ll dis[25][25];
int t[1 << 25][2];
ll f[1 << 25];
inline ll sqr(int x) { return x * x; }
inline ll di(int a, int b) { return sqr(x[a] - x[b]) + sqr(y[a] - y[b]); }
signed main() {
    scanf("%d%d%d", &x[24], &y[24], &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x[i], &y[i]);
    }
    for (int i = 0; i < n; i++) {
        dis[i][i] = di(i, 24);
        for (int j = i + 1; j < n; j++) {
            dis[i][j] = dis[j][i] = di(i, j);
        }
    }
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for (int p = 0; p < (1 << n); p++) {
        int t1 = 0;
        while ((p >> t1) & 1) t1++;
        if (t1 >= n) break;
        int tmp = f[p] + dis[t1][t1] + dis[t1][t1];
        int pp = p | (1 << t1);
        if (f[pp] > tmp) {
            f[pp] = tmp;
            t[pp][0] = t1;
            t[pp][1] = -1;
        }
        for (int t2 = t1 + 1; t2 < n; t2++) {
            if ((p >> t2) & 1) continue;
            int tmp = f[p] + dis[t1][t2] + dis[t1][t1] + dis[t2][t2];
            int pp = p | (1 << t1) | (1 << t2);
            if (f[pp] > tmp) {
                t[pp][0] = t1;
                t[pp][1] = t2;
                f[pp] = tmp;
            }
        }
    }
    int p = (1 << n) - 1;
    printf("%lld\n", f[p]);
    while (p) {
        int t1 = t[p][0], t2 = t[p][1];
        if (t2 == -1) {
            printf("0 %d ", t1 + 1);
            p ^= 1 << t1;
            continue;
        }
        printf("0 %d %d ", t1 + 1, t2 + 1);
        p ^= 1 << t1;
        p ^= 1 << t2;
    }
    puts("0");
    return 0;
}
