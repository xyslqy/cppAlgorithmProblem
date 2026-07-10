#include <bits/stdc++.h>
constexpr int maxn = 20010;
int n, m;
struct node {
    int a, b, c;
};
std::vector<node> ps;
int f[2 * maxn];
inline int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
inline void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    f[fx] = fy;
}
int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= 2 * n; i++) f[i] = i;
    for (int i = 1; i <= m; i++) {
        node x;
        std::cin >> x.a >> x.b >> x.c;
        ps.push_back(x);
    }
    std::sort(ps.begin(), ps.end(), [&](node x, node y) { return x.c > y.c; });
    for (auto _ : ps) {
        int a = _.a, b = _.b, c = _.c;
        if (find(a) == find(b)) {
            std::cout << c;
            return 0;
        }
        merge(a, b + n);
        merge(b, a + n);
    }
    puts("0");
    return 0;
}
