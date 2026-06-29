#include <bits/stdc++.h>
inline int read() {
    int x = 0, c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) x = x * 10 - '0' + c, c = getchar();
    return x;
}
inline int pla(int x, int y) {
    if (x <= 3) {
        if (y <= 3) return 1;
        if (y >= 4 && y <= 6) return 2;
        return 3;
    }
    if (x >= 4 && x <= 6) {
        if (y <= 3) return 4;
        if (y >= 4 && y <= 6) return 5;
        return 6;
    }
    if (y <= 3) return 7;
    if (y >= 4 && y <= 6) return 8;
    return 9;
}
bool fd[30][10];
struct node {
    int x, y;
} s[100];
int tot = 0;
int cnt[100];
int sum = 0;
int ans = -1, tmp = 0;
inline int abs(int x) { return x < 0 ? -x : x; }
inline int min(int x, int y) { return x < y ? x : y; }
inline int max(int x, int y) { return x > y ? x : y; }
inline int dis(int i, int j) {
    if (i == 1 || j == 1 || i == 9 || j == 9) return 6;
    if (i == 2 || j == 2 || i == 8 || j == 8) return 7;
    if (i == 3 || j == 3 || i == 7 || j == 7) return 8;
    if (i == 4 || j == 4 || i == 6 || j == 6) return 9;
    return 10;
}
void dfs(int p) {
    if (p > tot) {
        ans = max(ans, tmp);
        return;
    }
    int i = s[p].x, j = s[p].y;
    for (int num = 1; num <= 9; num++) {
        if (!fd[pla(i, j)][num] && !fd[9 + i][num] && !fd[18 + j][num]) {
            fd[pla(i, j)][num] = fd[9 + i][num] = fd[18 + j][num] = 1;
            tmp += dis(i, j) * num;
            dfs(p + 1);
            tmp -= dis(i, j) * num;
            fd[pla(i, j)][num] = fd[9 + i][num] = fd[18 + j][num] = 0;
        }
    }
}

int main() {
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            int x = read();
            if (x == 0) {
                s[++tot].x = i;
                s[tot].y = j;
            } else {
                cnt[pla(i, j)]++;
                cnt[9 + i]++;
                cnt[18 + j]++;
                fd[pla(i, j)][x] = fd[9 + i][x] = fd[18 + j][x] = 1;
                sum++;
                tmp += dis(i, j) * x;
            }
        }
    }
    std::sort(s + 1, s + 1 + tot, [&](node a, node b) {
        return max(cnt[pla(a.x, a.y)], max(cnt[a.x + 9], cnt[a.y + 18])) >
               max(cnt[pla(b.x, b.y)], max(cnt[b.x + 9], cnt[b.y + 18]));
    });
    dfs(1);
    std::cout << ans;
    return 0;
}
