#include <bits/stdc++.h>
inline int read() {
    int x = 0, c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) {
        x = x * 10 - '0' + c;
        c = getchar();
    }
    return x;
}
const int N = 10010;
int n, m;
int dfn[N], low[N], tot = 0, cnt = 0;
std::vector<int> e[N];
std::stack<int> st;
std::vector<int> ans[N];
bool ins[N];
template <typename T>
inline T min(T x, T y) {
    return x < y ? x : y;
}
void dfs(int x) {
    low[x] = dfn[x] = ++tot;
    st.push(x);
    ins[x] = 1;
    for (int y : e[x]) {
        if (!dfn[y]) {
            dfs(y);
            low[x] = min(low[y], low[x]);
        } else if (ins[y])
            low[x] = min(low[x], dfn[y]);
    }
    if (low[x] == dfn[x]) {
        cnt++;
        for (;;) {
            int y = st.top();
            st.pop();
            ans[cnt].push_back(y);
            ins[y] = 0;
            if (x == y) break;
        }
        std::sort(ans[cnt].begin(), ans[cnt].end());
    }
}
int main() {
    n = read();
    m = read();
    for (int i = 1; i <= m; i++) {
        int u = read();
        int v = read();
        if (u == v) continue;
        e[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) dfs(i);
    }
    std::sort(
        ans + 1, ans + 1 + cnt,
        [&](std::vector<int> a, std::vector<int> b) { return a[0] < b[0]; });
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++) {
        for (int x : ans[i]) {
            printf("%d ", x);
        }
        puts("");
    }
    return 0;
}
