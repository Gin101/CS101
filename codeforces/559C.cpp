#include <iostream>
#include <algorithm>

using namespace std;

const int maxHW = 2e5 + 1;
int num[maxHW] = {0};
int num2[maxHW] = {0};
const int maxN = 2001;
int dp[maxN] = {0};
const int MOD = 1e9 + 7;
struct Black {
    int r = 0;
    int c = 0;
    int s = 0;
} b[maxN];

bool cmp(Black x, Black y) {
    return x.r != y.r ? x.r < y.r : x.c < y.c;
}
int ope(int n, int m) {
    return 1ll * num2[n] * num[m] % MOD * num[n - m] % MOD;
}
int main()
{
    int h = 0;
    int w = 0;
    int n = 0;
    cin >> h >> w >> n;

    num2[0] = 1;
    num[0] = 1;
    num[1] = 1;

    for (int i = 2; i <= h + w; i++) {
        num[i] = MOD - 1ll * MOD / i * num[MOD % i] % MOD;
    }
    for (int i = 1; i <= h + w; i++) {
        num2[i] = 1ll * num2[i - 1] * i % MOD;
        num[i] = 1ll * num[i - 1] * num[i] % MOD;
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i].r >> b[i].c;
        b[i].s = b[i].r + b[i].c;
    }

    b[++n] = (Black){h, w, h + w};
    sort(b + 1, b + n + 1, cmp);

    for (int i = 1; i <= n; i++) {
        dp[i] = ope(b[i].s - 2, b[i].r - 1);
        for (int j = 1; j < i; j++) {
            if (b[j].r <= b[i].r && b[j].c <= b[i].c) {
                dp[i] = (dp[i] - 1ll * dp[j] * ope(b[i].s - b[j].s, b[i].r - b[j].r)) % MOD;
            }
        }
    }
	
    cout << (dp[n] + MOD) % MOD << endl;

	return 0;
}