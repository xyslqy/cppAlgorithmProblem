#include <bits/stdc++.h>
template <typename T>
inline T read(T& x) {
    x = 0;
    int c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) x = x * 10 - '0' + c, c = getchar();
    return x;
}
template <typename T>
inline T min(T x, T y) {
    return x < y ? x : y;
}
template <typename T>
inline T max(T x, T y) {
    return x > y ? x : y;
}
const int N = 1e5 + 10, P = 1000117;
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, -1, 1, 1, -1};
int n, m, c;
struct hash {
    int px[25 * N], py[25 * N], v[25 * N], head[P], nxt[25 * N], tot = 0;
    inline void ins(int x, int y, int vv) {
        int pos = (1ll * (x - 1) * n + y - 1) % P;
        nxt[++tot] = head[pos];
        head[pos] = tot;
        px[tot] = x;
        py[tot] = y;
        v[tot] = vv;
    }
    inline int ask(int x, int y) {
        for (int pos = head[(1ll * (x - 1) * n + y - 1) % P]; pos;
             pos = nxt[pos])
            if (px[pos] == x && py[pos] == y) return v[pos];
        return 0;
    }
    inline void clear() {
        memset(head, 0, sizeof(head));
        tot = 0;
    }
} mp, col, tem;

int xx[N], yy[N];
int cnt = 0;
std::vector<int> G[N * 25];
std::queue<std::pair<int, int>> Q, q;
bool isok[N * 25];
inline void add(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
}
inline void bfs(int sx, int sy, int cc) {
    int tx, ty;
    while (!q.empty()) q.pop();
    q.push({sx, sy});
    col.ins(sx, sy, cc);
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if ((tx = x + dx[i]) && tx <= n && (ty = y + dy[i]) && ty <= m &&
                mp.ask(tx, ty) > 0 && !col.ask(tx, ty)) {
                col.ins(tx, ty, cc);
                q.push({tx, ty});
            }
        }
    }
}
inline bool bfs2(int sx, int sy) {
    int tx, ty, tcl;
    q.push({sx, sy});
    tem.ins(sx, sy, -1);
    int ncl = -1;
    int t;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++) {
            if ((tx = x + dx[i]) && tx <= n && (ty = y + dy[i]) && ty <= m &&
                (t = mp.ask(tx, ty)) && !tem.ask(tx, ty)) {
                if (t > 0) {
                    tcl = col.ask(tx, ty);
                    if (ncl == -1)
                        ncl = tcl;
                    else if (ncl != col.ask(tx, ty))
                        return 0;
                } else if (t == -1) {
                    tem.ins(tx, ty, -1);
                    q.push({tx, ty});
                }
            }
        }
    }
    return 1;
}
inline bool ncon() {
    col.clear();
    int coltot = 0;
    while (!Q.empty()) {
        int x = Q.front().first, y = Q.front().second;
        Q.pop();
        if (col.ask(x, y)) continue;
        bfs(x, y, ++coltot);
    }
    tem.clear();
    for (int i = 1; i <= c; i++) {
        if (!tem.ask(xx[i], yy[i])) {
            if (!bfs2(xx[i], yy[i])) return 1;
        }
    }
    return 0;
}
int dfn[N*25], dfnc = 0;
bool iscut[N * 24];
int dfs(int x, int fa) {
    dfn[x] = ++dfnc;
    int chd = 0, lowv, lowu = dfn[x];
    for (int y : G[x]) {
        if (y == fa) continue;
        if (!dfn[y]) {
            chd++;
            if ((lowv = dfs(y, x)) >= dfn[x]) iscut[x] = 1;
            if (lowv < lowu) lowu = lowv;
        } else if (lowu > dfn[y])
            lowu = dfn[y];
    }
    if (!fa && chd == 1) iscut[x] = 0;
    return lowu;
}
inline bool check() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!mp.ask(i, j)) {
                for (int k = 0; k < 4; k++) {
                    int tx = i + dx[k], ty = j + dy[k];
                    if (1 <= tx && tx <= n && 1 <= ty && ty <= m &&
                        !mp.ask(tx, ty)) {
                        return 0;
                    }
                }
                return 1;
            }
        }
    }
    return 0;
}
void solve() {
    for (int i = 1; i <= cnt; i++) G[i].clear();
    cnt = dfnc = 0;
    memset(isok, 0, sizeof(isok));
    memset(iscut, 0, sizeof(iscut));
    memset(dfn, 0, sizeof(dfn));
    mp.clear();
    read(n);
    read(m);
    read(c);
    for (int i = 1; i <= c; i++) {
        read(xx[i]);
        read(yy[i]);
        mp.ins(xx[i], yy[i], -1);
    }
    if (1ll * n * m - c < 2ll) {
        puts("-1");
        return;
    }
    if (1ll * n * m - c == 2ll) {
        puts(check() ? "0" : "-1");
        return;
    }
    for (int i = 1; i <= c; i++) {
        for (int j = max(1, xx[i] - 2); j <= min(n, xx[i] + 2); j++) {
            for (int k = max(1, yy[i] - 2); k <= min(m, yy[i] + 2); k++) {
                int t;
                if (!(t = mp.ask(j, k))) {
                    mp.ins(j, k, ++cnt);
                    Q.push({j, k});
                    isok[cnt] = max(abs(j - xx[i]), abs(k - yy[i])) <= 1;
                    int tt;
                    for (int l = 0; l < 4; l++)
                        if (j + dx[l] >= 1 && j + dx[l] <= n &&
                            k + dy[l] >= 1 && k + dy[l] <= m &&
                            (tt = mp.ask(j + dx[l], k + dy[l])) > 0)
                            add(cnt, tt);
                } else if (t > 0 && max(abs(j - xx[i]), abs(k - yy[i])) <= 1)
                    isok[t] = 1;
            }
        }
    }
    if (ncon()) {
        puts("0");
        return;
    }
    if (n == 1 || m == 1) {
        puts("1");
        return;
    }
    for (int i = 1; i <= cnt; i++) {
        if (!dfn[i]) {
            dfs(i, 0);
        }
        if (isok[i] && iscut[i]) {
            puts("1");
            return;
        }
    }
    puts("2");
    return;
}
int main() {
    int t;
    read(t);
    while (t--) {
        solve();
    }
}
