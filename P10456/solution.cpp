#include <bits/stdc++.h>

#include <cstdio>
bool mp[5][5];
int ansx[100], ansy[100], tot, ans = 0x3f3f3f3f, ANSx[100], ANSy[100];
void upd(int x, int y) {
    for (int i = 1; i <= 4; i++) mp[x][i] ^= 1;
    for (int i = 1; i <= 4; i++) mp[i][y] ^= 1;
    mp[x][y] ^= 1;
}
bool check() {
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (mp[i][j]) return false;
        }
    }
    return true;
}
void dfs(int now) {
    int x = now / 4 + 1, y = now % 4 + 1;
    if (x == 5) {
        if (tot < ans && check()) {
            ans = tot;
            for (int i = 1; i <= ans; i++) {
                ANSx[i] = ansx[i];
                ANSy[i] = ansy[i];
            }
        }
        return;
    }
    dfs(now + 1);
    tot++;
    ansx[tot] = x;
    ansy[tot] = y;
    upd(x, y);
    dfs(now + 1);
    tot--;
    upd(x, y);
    return;
}
int main() {
    for (int i = 1; i <= 4; i++) {
        std::string s;
        std::cin>>s;
        for (int j = 1; j <= 4; j++) {
            if (s[j-1] == '+') mp[i][j] = 1;
        }
    }
    dfs(0);
    printf("%d\n", ans);
    for (int i = 1; i <= ans; i++) {
        printf("%d %d\n", ANSx[i], ANSy[i]);
    }
    return 0;
}
