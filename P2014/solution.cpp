#include <bits/stdc++.h>

#include <cstdio>
int inline read() {
    int x = 0;
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}
const int maxn = 305;
int n, m;
int s[maxn];
int f[maxn][maxn];
std::vector<int> e[maxn];
int inline max(int x, int y) { return x > y ? x : y; }
void dfs(int x) {
    for (int y : e[x]) {
        dfs(y);
        for (int i = m; i >= 1; i--) {
            for (int j = 0; j <= i; j++) {
                f[x][i] = max(f[y][j] + f[x][i - j], f[x][i]);
            }
        }
    }
    for (int i = m; i > 0; i--) {
        f[x][i] = f[x][i - 1] + s[x];
    }
}
int main() {
    n = read();
    m = read() + 1;
    for (int i = 1; i <= n; i++) {
        int k = read();
        e[k].push_back(i);
        s[i] = read();
    }
    dfs(0);
    printf("%d", f[0][m]);
    return 0;
}
