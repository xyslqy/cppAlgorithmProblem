#include <bits/stdc++.h>
int n;
bool c[10000][10000];
int qpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res *= a;
        b >>= 1;
        a *= a;
    }
    return res;
}
void b(int siz) {
    if (siz == 1) return;
    int lsiz = siz / 3;
    b(lsiz);
    for (int i = 1; i <= lsiz; i++) {
        for (int j = 1; j <= lsiz; j++) {
            c[i + 2 * lsiz][j + 2 * lsiz] = c[i + lsiz][j + lsiz] =
                c[i][j + 2 * lsiz] = c[i + 2 * lsiz][j] = c[i][j];
        }
    }
}
int main() {
    scanf("%d", &n);
    c[1][1] = true;
    b(qpow(3,8));
    while (n != -1) {
        int siz = qpow(3, n - 1);
        for (int i = 1; i <= siz; i++) {
            for (int j = 1; j <= siz; j++) {
                if (c[i][j])
                    printf("X");
                else
                    printf(" ");
            }
            puts("");
        }
        printf("-\n");
        scanf("%d", &n);
    }
    return 0;
}
