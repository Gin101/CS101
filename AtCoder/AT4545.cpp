#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 1e3;
struct Block {
    int w = 0;
    int s = 0;
    long long v = 0;
} b[maxN];
long long dp[10000000] = {0};

bool cmp(Block x, Block y) {
    return x.w + x.s < y.w + y.s;
}

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> b[i].w >> b[i].s >> b[i].v;
    }

    sort(b, b + n, cmp);
    for (int i = 0; i < n; i++) {
        for (int j = b[i].s; j >= 0; j--) {
            dp[j + b[i].w] = max(dp[j + b[i].w], dp[j] + b[i].v);
        }
    }

    cout << *max_element(dp, dp + 10000000) << endl;

	return 0;
}