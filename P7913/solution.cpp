#include <bits/stdc++.h>
using namespace std;
int n, m1, m2, ans = 0;
int s1[100005];
int s2[100005];
int t1[100005];
int t2[100005];
struct node {
    int x, y;
};
struct l {
    int id, t;
    bool operator<(const l& x) const {
        if (t != x.t) {
            return t > x.t;
        }
        return id > x.id;
    }
};
bool cmp(node x, node y) { return x.x < y.x; }
node a[100005];
node b[100005];
void find1() {
    priority_queue<int, vector<int>, greater<int> > p;
    priority_queue<l> q;
    for (int i = 1; i <= n; i++) {
        p.push(i);
    }
    for (int i = 0; i < m1; i++) {
        while (!q.empty() && q.top().t < a[i].x) {
            p.push(q.top().id);
            q.pop();
        }
        if (!p.empty()) {
            t1[p.top()]++;
            q.push(l{p.top(), a[i].y});
            p.pop();
        }
    }
    for (int i = 1; i <= n; i++) {
        s1[i] = s1[i - 1] + t1[i];
    }
}
void find2() {
    priority_queue<int, vector<int>, greater<int> > p;
    priority_queue<l> q;
    for (int i = 1; i <= n; i++) {
        p.push(i);
    }
    for (int i = 0; i < m2; i++) {
        while (!q.empty() && q.top().t < b[i].x) {
            p.push(q.top().id);
            q.pop();
        }
        if (!p.empty()) {
            t2[p.top()]++;
            q.push(l{p.top(), b[i].y});
            p.pop();
        }
    }
    for (int i = 1; i <= n; i++) {
        s2[i] = s2[i - 1] + t2[i];
    }
}
int main() {
    cin >> n >> m1 >> m2;
    for (int i = 0; i < m1; i++) cin >> a[i].x >> a[i].y;
    for (int i = 0; i < m2; i++) cin >> b[i].x >> b[i].y;
    sort(a, a + m1, cmp);
    sort(b, b + m2, cmp);
    find1();
    find2();
    for (int i = 0; i <= n; i++) {
        ans = max(ans, s1[i] + s2[n - i]);
    }
    cout << ans;
    return 0;
}
