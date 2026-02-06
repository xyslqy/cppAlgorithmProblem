#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500005;
int a[N], b[N], c[N], n;
bool solve(char cc) {
    deque<int> q1,q2;
    string ans,s;
    ans.push_back(cc);
    s.push_back('L');
    if (cc == 'L') {
        for (int i = 2; i < c[1]; i++) q1.push_back(i);
        for (int i = n; i > c[1]; i--) q2.push_back(i);
    } else {
        for (int i = 1; i < c[n]; i++) q1.push_back(i);
        for (int i = n - 1; i > c[n]; i--) q2.push_back(i);
    }
    while (q1.size() > 0 || q2.size() > 0) {
        int x1 = q1.size() ? q1.front() : 0;
        int x2 = q2.size() ? q2.front() : 0;
        int y1 = q1.size() ? q1.back() : 0;
        int y2 = q2.size() ? q2.back() : 0;
        if (c[x1] == y1) {
            ans.push_back('L');
            s.push_back('L');
            q1.pop_front();
            q1.pop_back();
        } else if (c[x1] == y2) {
            ans.push_back('L');
            s.push_back('R');
            q1.pop_front();
            q2.pop_back();
        } else if (c[x2] == y1) {
            ans.push_back('R');
            s.push_back('L');
            q2.pop_front();
            q1.pop_back();
        } else if (c[x2] == y2) {
            ans.push_back('R');
            s.push_back('R');
            q2.pop_front();
            q2.pop_back();
        } else {
            return false;
        }
    }
    reverse(s.begin(), s.end());
    ans += s;
    cout << ans << endl;
    return true;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) b[i] = 0;
        n *= 2;
        c[0] = -1;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (b[a[i]]) {
                c[b[a[i]]] = i;
                c[i] = b[a[i]];
            } else {
                b[a[i]] = i;
            }
        }
        if (!solve('L') && !solve('R')) puts("-1");
    }
    return 0;
}
