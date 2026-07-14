#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
const int MOD = 998244353;
int n, k;
vector<int> to[MAXN];
int dp[MAXN][MAXN];
int pref_cur[MAXN], pref_child[MAXN], new_dp[MAXN];

void dfs(int u, int fa) {
    dp[u][0] = 1;
    for (int v : to[u]) {
        if (v == fa) continue;
        dfs(v, u);
        for (int i = 0; i <= k; i++) {
            pref_cur[i] = dp[u][i] + (i ? pref_cur[i - 1] : 0);
            if (pref_cur[i] >= MOD) pref_cur[i] -= MOD;

            pref_child[i] = dp[v][i] + (i ? pref_child[i - 1] : 0);
            if (pref_child[i] >= MOD) pref_child[i] -= MOD;
        }
        long long sum_child = pref_child[k];
        for (int i = 0; i <= k; i++) new_dp[i] = 0;
        for (int i = 0; i <= k; i++) {
            new_dp[i] = (new_dp[i] + 1LL * dp[u][i] * sum_child) % MOD;
        }
        for (int i = 0; i <= k; i++) {
            int lim = min(i - 1, k - i - 1);
            if (lim >= 0) {
                new_dp[i] =
                    (new_dp[i] + 1LL * dp[u][i] * pref_child[lim]) % MOD;
            }
        }
        for (int j = 0; j <= k; j++) {
            int lim = min(j, k - j - 1);
            if (lim >= 0) {
                new_dp[j + 1] =
                    (new_dp[j + 1] + 1LL * dp[v][j] * pref_cur[lim]) % MOD;
            }
        }
        for (int i = 0; i <= k; i++) {
            dp[u][i] = new_dp[i];
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        to[u].push_back(v);
        to[v].push_back(u);
    }
    dfs(1, 0);
    int ans = 0;
    for (int i = 0; i <= k; i++) {
        ans += dp[1][i];
        if (ans >= MOD) ans -= MOD;
    }
    printf("%d\n", ans);
    return 0;
}
