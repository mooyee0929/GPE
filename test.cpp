/* UVA10404 Bachet's Game */

#include <bits/stdc++.h>

using namespace std;

const int N = 1000000;
const int M = 10;
int s[M];
char dp[N + 1];

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        for (int i = 0; i < m; i++) scanf("%d", &s[i]);

        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = 0;
            for (int j = 0; j < m; j++)
                if (i - s[j] >= 0 && dp[i - s[j]] == 0) {
                    dp[i] = 1;
                    break;
                }
        }

        puts(dp[n] ? "Stan wins" : "Ollie wins");
    }

    return 0;
}
