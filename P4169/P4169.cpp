#include <bits/stdc++.h>
const int maxn = 9e6 + 10;
int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}
inline void umax(int& x, int y) { x = x > y ? x : y; }
inline void umin(int& x, int y) { x = x < y ? x : y; }
struct opt {
    int x, y, id;
    bool t;
    const bool operator<(const opt& a) { return x <= a.x; }
    opt() { t = 0, x = 0, y = 0; }
    opt(bool t, int x, int y, int id) : t(t), x(x), y(y), id(id) {};
};
opt a[maxn], q[maxn], tmp[maxn];
int n, m, lx, ly;
int Ans[maxn];
int tree[maxn];
void add(int x, int c) {
    for (; x <= ly; x += x & -x) umax(tree[x], c);
}
void clear(int x) {
    for (; x <= ly; x += x & -x) {
        if (!tree[x]) break;
        tree[x] = 0;
    }
}
int ask(int x) {
    int res = 0;
    for (; x; x -= x & -x) umax(res, tree[x]);
    return res;
}
void cdq(int l, int r) {
    if (l >= r) return;
    int mid = (l + r) >> 1;
    cdq(l, mid);
    cdq(mid + 1, r);
    int j = l;
    for (int i = mid + 1; i <= r; i++) {
        if (q[i].t) continue;
        for (; j <= mid && q[j].x <= q[i].x; j++) {
            if (!q[j].t) continue;
            add(q[j].y, q[j].x + q[j].y);
        }
        int t = ask(q[i].y);
        if (t) umin(Ans[q[i].id], q[i].x + q[i].y - t);
    }
    for (int i = l; i <= j; i++)
        if (q[i].t) clear(q[i].y);
    std::merge(q + l, q + mid + 1, q + mid + 1, q + r + 1, tmp + l);
    for (int i = l; i <= r; i++) q[i] = tmp[i];
}
void del() {
    int rx = 0, ry = 0;
    m = 0;
    for (int i = 1; i <= n; i++) {
        if (!q[i].t) umax(rx, q[i].x), umax(ry, q[i].y);
    }
    for (int i = 1; i <= n; i++) {
        if (q[i].x <= rx && q[i].y <= ry) tmp[++m] = q[i];
    }
    for (int i = 1; i <= m; i++) {
        q[i] = tmp[i];
    }
}

int main() {
    memset(Ans, 0x3f, sizeof(Ans));
    n = read();
    m = read();
    for (int i = 1; i <= n; i++) {
        int x = read() + 1, y = read() + 1;
        q[i] = opt(true, x, y, i);
        umax(lx, x);
        umax(ly, y);
    }
    while (m--) {
        int t = read(), x = read() + 1, y = read() + 1;
        q[++n] = opt(t & 1, x, y, n);
        umax(lx, x);
        umax(ly, y);
    }
    for (int i = 1; i <= n; i++) {
        a[i] = q[i];
    }
    lx++, ly++;
    del();
    cdq(1, m);
    for (int i = 1; i <= n; i++) {
        q[i] = a[i];
        q[i].x = lx - q[i].x;
    }
    del();
    cdq(1, m);
    for (int i = 1; i <= n; i++) {
        q[i] = a[i];
        q[i].y = ly - q[i].y;
    }
    del();
    cdq(1, m);
    for (int i = 1; i <= n; i++) {
        q[i] = a[i];
        q[i].x = lx - q[i].x;
        q[i].y = ly - q[i].y;
    }
    del();
    cdq(1, m);
    for (int i = 1; i <= n; i++) {
        if (!a[i].t) {
            printf("%d\n", Ans[a[i].id]);
        }
    }

    return 0;
}
