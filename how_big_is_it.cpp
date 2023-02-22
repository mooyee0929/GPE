//unknown
#include <bits/stdc++.h>

using namespace std;

const int M = 8;
double r[M], center[M], res, res2, ans;
int m;

void search(int k)
{
    if(k != m) {
        double tmp;
        res = 0;
        for(int i = 0; i < k; i++) {
            tmp = 2 * sqrt(r[i] * r[k]);
            tmp += center[i];
            tmp = max(tmp, r[k]);
            res = max(res, tmp);
        }

        center[k] = res;
        res2 = max(res2, center[k] + r[k]);
        search(k + 1);
    }
}

void cal()
{
    ans = 1e60;
    do {
        res2 = r[0] * 2;
        center[0] = r[0];
        search(1);
        ans = min(ans, res2);
    } while(next_permutation(r , r + m));
}

int main()
{
    int n;
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &m);
        for(int i = 0; i < m; i++)
            scanf("%lf", &r[i]);

        sort(r, r + m);

        if(m == 1)
            ans = r[0] * 2;
        else
            cal();

        printf("%.3lf\n", ans);
    }

    return 0;
}