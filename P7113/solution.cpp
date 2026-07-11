#include <bits/stdc++.h>
using ll = __int128;
template <typename T>
inline void write(T x) {
    static int st[200];
    int top = 0;
    while (x) st[++top] = x % 10, x /= 10;
    while (top) putchar(st[top--] + '0');
}
struct num {
    ll p = 0, q = 1;
};
inline num operator/(num a, ll b) {
    ll tmp = std::__gcd(b, a.p);
    return {a.p / tmp, b / tmp * a.q};
}
inline num operator+(num a, num b) {
    num c;
    c.p = a.p * b.q + b.p * a.q;
    c.q = a.q * b.q;
    ll tmp = std::__gcd(c.p, c.q);
    c.p /= tmp;
    c.q /= tmp;
    return c;
}
constexpr int maxn = 1e5 + 10;
int n, m;
int r[maxn];
num f[maxn];
std::vector<int> to[maxn];
int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int tmp, x;
        std::cin >> tmp;
        while (tmp--) {
            std::cin >> x;
            r[x]++;
            to[i].push_back(x);
        }
    }
    std::queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!r[i]) q.push(i), f[i].p = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        num tmp = f[x] / to[x].size();
        for (int y : to[x]) {
            f[y] = f[y] + tmp;
            r[y]--;
            if (!r[y]) q.push(y);
        }
    }
    for (int i = 1; i <= n; i++)
        if (to[i].empty())
            write(f[i].p), putchar(' '), write(f[i].q), putchar('\n');
    return 0;
}
