#include <bits/stdc++.h>
const int maxn = 1e5 + 10;
int n, m;
int e[22][22];
int f[1 << 22];
char str[maxn];
int calc(int a, int add,int pos) {
    int res = 0;
    for (int i = 0; i < m; i++) {
        if (i == add) continue;
        if (!((a >> i) & 1)) {
            res -= pos*e[add][i];
            // printf("sub %d %d %d\n",add,i,e[add][i]);
        } else {
            res += pos*e[add][i];
            // printf("add %d %d %d\n",add,i,e[add][i]);
        }
    }
    // printf("%b %d %d\n", a, add, res);
    return res;
}
int main() {
    std::cin >> n >> m >> (str + 1);
    for (int i = 2; i <= n; i++) {
        e[str[i] - 'a'][str[i - 1] - 'a']++;
        e[str[i - 1] - 'a'][str[i] - 'a']++;
    }
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for (int i = 1; i < (1 << m); i++) {
        for (int j = 0; j < m; j++) {
            if (!((i >> j) & 1)) continue;
            f[i] = std::min(f[i ^ (1 << j)] + calc(i, j,__builtin_popcount(i)), f[i]);
        }
    }
    std::cout << f[(1 << m) - 1];
}
