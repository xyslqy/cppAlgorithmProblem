#include <bits/stdc++.h>
using ll = long long;
constexpr int maxn = 5e5 + 10;
int n, top;
int fa[maxn], st[maxn];
ll k[maxn], f[maxn], ans;
char c[maxn];
std::vector<int> to[maxn];
inline void dfs(int x) {
    int t = 0;
    if (c[x] == '(') {
        st[++top] = x;
    } else if (top) {
        t = st[top--];
        f[x] = f[fa[t]] + 1;
    }
    k[x] = k[fa[x]] + f[x];
    for (int y : to[x]) {
        dfs(y);
    }
    if (t)
        st[++top] = t;
    else if (top)
        top--;
}
int main() {
    std::cin >> n >> (c + 1);
    for (int i = 2; i <= n; i++) std::cin >> fa[i], to[fa[i]].push_back(i);
    dfs(1);
    for (int i = 1; i <= n; i++) {
        ans ^= k[i] * i;
    }
    std::cout << ans;
    return 0;
}
