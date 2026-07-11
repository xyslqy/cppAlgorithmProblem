#include <bits/stdc++.h>
std::unordered_map<std::string, int> mp;
int n;
bool check(std::string& s) {
    long long a, b, c, d, port;
    if (sscanf(s.c_str(), "%lld.%lld.%lld.%lld:%lld", &a, &b, &c, &d, &port) !=
        5)
        return false;
    if (a < 0 || a > 255 || b < 0 || b > 255 || c < 0 || c > 255 || d < 0 ||
        d > 255 || port < 0 || port > 65535)
        return false;
    std::stringstream ss;
    ss << a << '.' << b << '.' << c << '.' << d << ':' << port;
    return ss.str() == s;
}
int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::string t, s;
        std::cin >> t >> s;
        if (!check(s)) {
            puts("ERR");
            continue;
        }
        if (t[0] == 'S') {
            if (mp.find(s) != mp.end())
                puts("FAIL");
            else
                puts("OK"), mp[s] = i;
        } else {
            if (mp.find(s) != mp.end())
                printf("%d\n", mp[s]);
            else
                puts("FAIL");
        }
    }
}
