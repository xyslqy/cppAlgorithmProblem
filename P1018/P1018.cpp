#include <bits/stdc++.h>
using namespace std;
const int maxn = 41, maxk = 7;
int n, k;
string str;
string num[maxn][maxn];
string f[maxn][maxk];
string smax(string a, string b) {
    if (a.empty()) return b;
    if (b.empty()) return a;
    if (a.size() != b.size()) return a.size() > b.size() ? a : b;
    return a > b ? a : b;
}
string smul(string a, string b) {
    if (a == "0" || b == "0") return "0";
    int x[1005] = {}, y[1005] = {}, z[1005] = {};
    int len = a.size() + b.size();
    int lena = a.size(), lenb = b.size();
    string c;
    for (int i = 0; i < lena; i++) x[lena - i - 1] = a[i] - '0';
    for (int i = 0; i < lenb; i++) y[lenb - i - 1] = b[i] - '0';
    for (int i = 0; i < lena; i++) {
        for (int j = 0; j < lenb; j++) {
            z[i + j] += x[i] * y[j];
            z[i + j + 1] += z[i + j] / 10;
            z[i + j] %= 10;
        }
    }
    while (!z[len - 1]) len--;
    for (int i = len - 1; i >= 0; i--) c += char(z[i] + '0');
    return c;
}
int main() {
    cin >> n >> k >> str;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            num[i][j] = str.substr(i, j - i + 1);
        }
        f[i][0] = num[0][i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k && j <= i; j++) {
            f[i][j] = "0";
            for (int p = 1; p <= i; p++) {
                f[i][j] = smax(f[i][j], smul(f[p - 1][j - 1], num[p][i]));
            }
        }
    }
    cout << f[n - 1][k];
    return 0;
}
