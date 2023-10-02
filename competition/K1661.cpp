#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

const int maxN = 1e4 + 1;
struct Tree {
    long long p = 0;
    long long r = 0;
    long long val = 0;
} tree[maxN];

long long dp[maxN] = {0};
bool cmp(Tree x, Tree y) {
    return x.p < y.p;
}
int main()
{
    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> tree[i].p;
    }
    for (int i = 1; i <= n; i++) {
        cin >> tree[i].r;
    }
    for (int i = 1; i <= n; i++) {
        cin >> tree[i].val;
    }
	
    sort(tree + 1, tree + n + 1, cmp);

    long long result = LONG_MIN;
    for (int i = 1; i <= n; i++) {
        dp[i] = tree[i].val;
        for (int j = 1; j < i; j++) {
            if (tree[j].p + tree[j].r <= tree[i].p - tree[i].r) {
                dp[i] = max(dp[i], tree[i].val + dp[j]);
            }
        }

        result = max(result, dp[i]);
    }
	
    cout << result << endl;

	return 0;
}