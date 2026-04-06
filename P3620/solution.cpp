#include <bits/stdc++.h>
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
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f;
int n, k, s0, s1, ans;
struct node {
    int l, r, v;
};
node d[maxn];
bool vis[maxn];
void del(int x) {
    vis[d[x].l] = true;
    vis[d[x].r] = true;
    d[x].l = d[d[x].l].l;
    d[x].r = d[d[x].r].r;
    d[d[x].l].r = x;
    d[d[x].r].l = x;
}
int heap[maxn], tot;
int inline val(int x) { return d[heap[x]].v; }
void up(int p) {
    while (p > 1) {
        if (val(p) > val(p / 2)) break;
        std::swap(heap[p], heap[p / 2]);
        p /= 2;
    }
}
void down(int p) {
    int s = p * 2;
    while (s <= tot) {
        if (s < tot && val(s) > val(s + 1)) s++;
        if (val(s) > val(p)) break;
        std::swap(heap[s], heap[p]);
        p = s;
        s = p * 2;
    }
}
void ins(int x) {
    heap[++tot] = x;
    up(tot);
}
int pop() {
    std::swap(heap[1], heap[tot--]);
    down(1);
    return heap[tot + 1];
}
int main() {
    n = read();
    k = read();
    s0 = read();
    for (int i = 1; i < n; i++) {
        s1 = read();
        d[i].l = i - 1;
        d[i].r = i + 1;
        d[i].v = s1 - s0;
        ins(i);
        s0 = s1;
    }
    d[0].v = d[n].v = inf;
    for (int i = 1; i <= k; i++) {
        int p = pop();
        while (vis[p]) p = pop();
        ans += d[p].v;
        d[p].v = d[d[p].l].v + d[d[p].r].v - d[p].v;
        del(p);
        ins(p);
    }
    printf("%d", ans);

    return 0;
}
