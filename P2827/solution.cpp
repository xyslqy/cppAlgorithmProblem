#include <bits/stdc++.h>

#include <utility>
const int inf = 0x3f3f3f3f;
int n, m, q, u, v, t;
int a[100005];
int read() {
    int x = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 - '0' + c;
        c = getchar();
    }
    return x;
}
std::queue<int> qu[4];
int main() {
    n = read();
    m = read();
    q = read();
    u = read();
    v = read();
    t = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    std::sort(a + 1, a + 1 + n, [&](int x, int y) { return x > y; });
    for (int i = 1; i <= n; i++) qu[1].push(a[i]);
    for (int i = 0; i < m; i++) {
        std::pair<int, int> p = std::max({
            std::make_pair(qu[1].empty() ? -inf : qu[1].front(), 1),
            std::make_pair(qu[2].empty() ? -inf : qu[2].front(), 2),
            std::make_pair(qu[3].empty() ? -inf : qu[3].front(), 3),
        });
        qu[p.second].pop();
        int x = p.first + i * q;
        int b = 1ll * x * u / v, c = x - b;
        qu[2].push(b - q - i * q);
        qu[3].push(c - q - i * q);
        if ((i + 1) % t == 0) printf("%d ", x);
    }
    puts("");
    for (int i = 1; i <= n + m; i++) {
        std::pair<int, int> p = std::max({
            std::make_pair(qu[1].empty() ? -inf : qu[1].front(), 1),
            std::make_pair(qu[2].empty() ? -inf : qu[2].front(), 2),
            std::make_pair(qu[3].empty() ? -inf : qu[3].front(), 3),
        });
        qu[p.second].pop();
        int x = p.first + m * q;
        if (i % t == 0) printf("%d ", x);
    }
    return 0;
}
