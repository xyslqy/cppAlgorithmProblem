#include <bits/stdc++.h>
const int N = 2e6, inf = 0x3f3f3f3f;
struct Splay {
    int fa, ch[2], mx, mxid, w, revflag;
} node[N];
#define fa(x) node[x].fa
#define ls(x) node[x].ch[0]
#define rs(x) node[x].ch[1]
inline void pushup(int x) {
    node[x].mx = node[x].w;
    node[x].mxid = x;
    if (ls(x) && node[ls(x)].mx > node[x].mx) {
        node[x].mx = node[ls(x)].mx;
        node[x].mxid = node[ls(x)].mxid;
    }
    if (rs(x) && node[rs(x)].mx > node[x].mx) {
        node[x].mx = node[rs(x)].mx;
        node[x].mxid = node[rs(x)].mxid;
    }
}
inline void reverse(int x) {
    std::swap(ls(x), rs(x));
    node[x].revflag ^= 1;
}
inline void pushdown(int x) {
    if (!node[x].revflag) return;
    reverse(ls(x));
    reverse(rs(x));
    node[x].revflag = 0;
}
inline int get(int x) { return x == rs(fa(x)); }
inline int nroot(int x) { return x == ls(fa(x)) || x == rs(fa(x)); }
inline void rotate(int x) {
    int y = fa(x), z = fa(y), d = get(x), dd = get(y);
    if (nroot(y)) node[z].ch[dd] = x;
    node[y].ch[d] = node[x].ch[!d];
    if (node[x].ch[!d]) fa(node[x].ch[!d]) = y;
    node[x].ch[!d] = y;
    fa(y) = x;
    fa(x) = z;
    pushup(y);
    pushup(x);
}
int st[N], tp;
inline void splay(int x) {
    int y = st[tp = 1] = x;
    while (nroot(y)) st[++tp] = y = fa(y);
    while (tp) pushdown(st[tp--]);
    for (; nroot(x); rotate(x)) {
        if (nroot(fa(x))) {
            rotate(get(x) == get(fa(x)) ? fa(x) : x);
        }
    }
}
inline void access(int x) {
    int y = 0;
    while (x) {
        splay(x);
        rs(x) = y;
        pushup(x);
        x = fa(y = x);
    }
}
inline void makeroot(int x) {
    access(x);
    splay(x);
    reverse(x);
}
inline int findroot(int x) {
    access(x);
    splay(x);
    while (ls(x)) x = ls(x);
    splay(x);
    return x;
}
inline int split(int x, int y) {
    makeroot(x);
    access(y);
    splay(y);
    return y;
}
inline void link(int x, int y) {
    makeroot(x);
    fa(x) = y;
}
inline void cut(int x, int y) {
    split(x, y);
    fa(x) = ls(y) = 0;
    pushup(x);
    pushup(y);
}
int n, m, ans = inf;
inline int read() {
    int x = 0;
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) {
        x = x * 10 - '0' + c;
        c = getchar();
    }
    return x;
}
struct edge {
    int x, y, a, b;
} e[N];
int main() {
    n = read();
    m = read();
    for (int i = 1; i <= m; i++) {
        e[i].x = read();
        e[i].y = read();
        e[i].a = read();
        e[i].b = read();
    }
    std::sort(e + 1, e + 1 + m, [&](edge x, edge y) { return x.a < y.a; });
    for (int i = 1; i <= m; i++) {
        int x = e[i].x, y = e[i].y, a = e[i].a, b = e[i].b;
        node[n + i].w = b;
        if (findroot(x) == findroot(y)) {
            split(x, y);
            int mx = node[y].mx, mxid = node[y].mxid;
            if (mx > b) {
                cut(e[mxid - n].x, mxid);
                cut(e[mxid - n].y, mxid);
                link(x, n + i);
                link(y, n + i);
            }
        } else {
            link(x, n + i);
            link(y, n + i);
        }
        if (findroot(1) == findroot(n)) {
            ans = std::min(ans, a + node[split(1, n)].mx);
        }
    }
    if (ans == inf)
        printf("-1");
    else
        printf("%d", ans);
    return 0;
}
