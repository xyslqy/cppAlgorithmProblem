#include <bits/stdc++.h>

#include <cstdio>
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
const int maxn = 1e5 + 10;
int n, m;
int t[maxn];
int main() {
    n = read();
    m = read();
    for (int i = 1; i <= n; i++) {
        t[i] = read();
    }
    return 0;
}
