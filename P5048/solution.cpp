#include <bits/stdc++.h>

int inline read() {
    int x = 0;
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
};
void write(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
    return;
}
const int maxn = 5e5 + 10, sqn = 900;
int n, m, bl, bs;
int a[maxn], f[sqn][sqn];
int L[sqn], R[sqn];
int tmp[maxn], p[maxn];
std::vector<int> vec[maxn];
int inline gb(int x) { return (x - 1) / bl + 1; }
int inline max(int x, int y) { return x > y ? x : y; }
int main() {
    n = read();
    m = read();
    bl = sqrt(n);
    bs = gb(n);
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        p[i] = vec[a[i]].size();
        vec[a[i]].push_back(i);
    }
    for (int i = 1; i <= bs; i++) {
        R[i] = i * bl;
        L[i] = R[i - 1] + 1;
    }
    R[bs] = n;
    for (int i = 1; i <= bs; i++) {
        for (int j = i; j <= bs; j++) {
            f[i][j] = f[i][j - 1];
            for (int k = L[j]; k <= R[j]; k++) {
                f[i][j] = max(f[i][j], ++tmp[a[k]]);
            }
        }
        for (int k = L[i]; k <= n; k++) {
            tmp[a[k]] = 0;
        }
    }
    int ans = 0;
    while (m--) {
        int l = read(), r = read();
        l ^= ans;
        r ^= ans;
        if (l > r) std::swap(l, r);
        int ql = gb(l), qr = gb(r);
        if (ql == qr) {
            ans = 0;
            for (int i = l; i <= r; i++) {
                ans = max(ans, ++tmp[a[i]]);
            }
            for (int i = l; i <= r; i++) tmp[a[i]] = 0;
        } else {
            ans = f[ql + 1][qr - 1];
            for (int i = l; i <= R[ql]; i++) {
                while (p[i] + ans < vec[a[i]].size() &&
                       vec[a[i]][p[i] + ans] <= r)
                    ans++;
            }
            for (int i = L[qr]; i <= r; i++) {
                while (p[i] - ans >= 0 && vec[a[i]][p[i] - ans] >= l) ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
