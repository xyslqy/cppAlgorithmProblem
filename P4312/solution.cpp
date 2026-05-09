#include <bits/stdc++.h>
const int N = 3e4 + 10;
struct Splay {
    int fa, ch[2], w, sum, revflag;
} node[N];
#define fa(x) node[x].fa
#define ls(x) node[x].ch[0]
#define rs(x) node[x].ch[1]
inline void pushup(int x) {
    node[x].sum = node[ls(x)].sum + node[rs(x)].sum + node[x].w;
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
    fa(node[x].ch[!d]) = y;
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
    for (; nroot(x); rotate(x))
        if (nroot(fa(x))) rotate(get(fa(x)) == get(x) ? fa(x) : x);
    pushup(x);
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
inline void split(int x, int y) {
    makeroot(x);
    access(y);
    splay(y);
}
inline void link(int x, int y) {
    makeroot(x);
    fa(x) = y;
}
inline void cut(int x, int y) {
    split(x, y);
    fa(x) = ls(y) = 0;
}
inline int findroot(int x) {
    access(x);
    splay(x);
    while (ls(x)) x = ls(x), pushdown(x);
    splay(x);
    return x;
}
int main() {
    int n, q;
    scanf("%d", &n);
    char op[20];
    for (int i = 1; i <= n; i++) scanf("%d", &node[i].w);
    scanf("%d", &q);
    int u, v;
    while (q--) {
        scanf("%s%d%d", op, &u, &v);
        if (op[0] == 'b') {
            if (findroot(u) == findroot(v)) {
                printf("no\n");
            } else {
                printf("yes\n");
                link(u, v);
            }
        } else if (op[0] == 'p') {
            splay(u);
            node[u].w = v;
            pushup(u);
        } else {
            if (findroot(u) != findroot(v))
                printf("impossible\n");
            else {
                split(u, v);
                printf("%d\n", node[v].sum);
            }
        }
    }
}
