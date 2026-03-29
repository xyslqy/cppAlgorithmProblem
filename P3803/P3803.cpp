#include <bits/stdc++.h>

#include <iostream>
const int maxn = 1e7 + 10;
const double PI = acos(-1);
struct complex {
    double x = 0, y = 0;
    complex() { x = 0, y = 0; }
    complex(double xx, double yy) { x = xx, y = yy; }
};
const complex operator+(complex x, complex y) {
    return complex(x.x + y.x, x.y + y.y);
}
const complex operator-(complex x, complex y) {
    return complex(x.x - y.x, x.y - y.y);
}
const complex operator*(complex a, complex b) {
    return complex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}
int n, m, lim;
complex a[maxn], b[maxn];
void fft(complex* a, int lim, int type) {
    if (lim == 1) return;
    complex a1[lim >> 1], a2[lim >> 1];
    for (int i = 0; i < lim; i += 2) {
        a1[i >> 1] = a[i];
        a2[i >> 1] = a[i + 1];
    }
    fft(a1, lim >> 1, type);
    fft(a2, lim >> 1, type);
    complex w = complex(1, 0),
            Wn = complex(cos(2 * PI / lim), type * sin(2 * PI / lim));
    for (int i = 0; i < (lim >> 1); i++, w = w * Wn) {
        a[i] = a1[i] + w * a2[i];
        a[i + (lim >> 1)] = a1[i] - w * a2[i];
    }
    return;
}
int main() {
    std::cin >> n >> m;
    for (lim = 1; lim <= n + m; lim *= 2);
    for (int i = 0; i <= n; i++) std::cin >> a[i].x;
    for (int i = 0; i <= m; i++) std::cin >> b[i].x;
    fft(a, lim, 1);
    fft(b, lim, 1);
    for (int i = 0; i < lim; i++) a[i] = a[i] * b[i];
    fft(a, lim, -1);
    for (int i = 0; i <= n + m; i++)
        std::cout << (int)(a[i].x / lim + 0.5) << " ";
    return 0;
}
