#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

const int maxN = 2e5 + 1;
struct Project {
    int a = 0;
    int b = 0;
    int p = 0;
} pr[maxN];
long long dp[maxN] = {0};

bool cmp(Project x, Project y) {
    return x.b < y.b;
}

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> pr[i].a >> pr[i].b >> pr[i].p;
    }

    sort(pr + 1, pr + n + 1, cmp);

    pr[0].b = INT_MIN;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        int l = 0;
        int r = i - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (pr[mid].b < pr[i].a) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        dp[i] = max(dp[i], dp[l] + pr[i].p);
    }

    cout << dp[n] << endl;

    return 0;
}