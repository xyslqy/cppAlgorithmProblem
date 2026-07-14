#include <bits/stdc++.h>
int n;
int dis[20][20];
int f[1 << 20][20];
void ckmin(int& x, int y) {
    if (x > y) x = y;
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dis[i][j]);
        }
    }
    memset(f, 0x3f, sizeof(f));
    f[1][0] = 0;
    for (int p = 1; p < (1 << n); p++) {
        for (int k = 0; k < n; k++) {
            if (((p >> k) & 1) == 0) continue;
            for (int t = 0; t < n; t++) {
                if ((p >> t) & 1) continue;
                ckmin(f[p | (1 << t)][t], f[p][k] + dis[t][k]);
            }
        }
    }
    printf("%d", f[(1 << n) - 1][n - 1]);
}
