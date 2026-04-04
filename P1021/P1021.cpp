#include <bits/stdc++.h>
int inline read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}
int inline min(int x, int y) { return x < y ? x : y; }
int n, k, cnt, ccnt, tot;
int f[1005];
int ans[1005];
int ANS[1005];
void dfs(int x) {
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    int i;
    for (i = 1;; i++) {
        for (int _ = 1, w = ans[_]; _ <= tot; _++, w = ans[_]) {
            if (i >= w) f[i] = min(f[i - w] + 1, f[i]);
        }
        if (f[i] > n) {
            i--;
            break;
        }
    }
    if (i > cnt) {
        cnt = i;
        ccnt = tot;
        for (int i = 1; i <= tot; i++) {
            ANS[i] = ans[i];
        }
    }
    if (tot == k) return;
    tot++;
    for (int j = ans[tot - 1] + 1; j <= i + 1; j++) {
        ans[tot] = j;
        dfs(x + 1);
    }
    tot--;
}
int main() {
    n = read();
    k = read();
    tot = 1;
    ans[1] = 1;
    dfs(1);
    for (int i = 1; i <= ccnt; i++) {
        printf("%d ", ANS[i]);
    }
    printf("\nMAX=%d", cnt);
    return 0;
}
