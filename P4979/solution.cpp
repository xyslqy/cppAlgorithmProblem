#include <bits/stdc++.h>
int inline read() {
    int x = 0;
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}
char inline gc() {
    char c = getchar();
    while (c != 'A' && c != 'B' && c != 'C') c = getchar();
    return c;
}
int n;
struct node {
    int l, r;
    mutable int v;
    node(int l, int r, int v) : l(l), r(r), v(v) {}
    bool operator<(const node& x) const { return l < x.l; }
};
std::set<node> odt;
auto split(int x) {
    auto it = odt.lower_bound(node(x, 0, 0));
    if (it != odt.end() && it->l == x) return it;
    --it;
    int l = it->l, r = it->r, v = it->v;
    odt.erase(it);
    odt.insert(node(l, x - 1, v));
    return odt.insert(node(x, r, v)).first;
}
void assign(int l, int r, int v) {
    auto itr = split(r + 1), itl = split(l);
    odt.erase(itl, itr);
    auto it = odt.insert(node(l, r, v)).first;
    if (prev(it) != odt.begin() && prev(it)->v == v) {
        int ll = prev(it)->l;
        odt.erase(prev(it), next(it));
        it = odt.insert(node(ll, r, v)).first;
    }
    if (next(it) != odt.end() && next(it)->v == v) {
        int ll = it->l, rr = next(it)->r;
        odt.erase(it, next(next(it)));
        odt.insert(node(ll, rr, v));
    }
}
bool query(int l, int r) {
    auto itr = split(r + 1), itl = split(l);
    int v = itl->v;
    for (auto i = itl; i != itr; i++) {
        if (i->v != v) return false;
    }
    odt.erase(itl, itr);
    auto it = odt.insert(node(l, r, v)).first;
    if (l != 1 && r != n) {
        if (prev(it)->v == itr->v) return false;
    }
    return true;
}
int k;
int main() {
    n = read();
    char ch = gc();
    int lst = 1;
    for (int i = 2; i <= n; i++) {
        char str = gc();
        if (ch != str) {
            odt.insert(node(lst, i - 1, ch));
            ch = str;
            lst = i;
        }
    }
    odt.insert(node(lst, n, ch));
    std::cin >> k;
    while (k--) {
        char ch = gc();
        int x = read(), y = read();
        if (ch == 'A') {
            char op = gc();
            assign(x, y, op);
        } else {
            if (query(x, y))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
