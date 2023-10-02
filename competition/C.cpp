#include <iostream>

using namespace std;

const int maxN = 5e5 + 1;
const int MOD = 998244353;
int dp[maxN] = {0};
int dp2[maxN] = {0};
int g[maxN] = {0};
struct Node {
    int a = 0;
    int b = 0;
} p[maxN];

bool cmp(Node x, Node y) {
    return x.a > y.a;
}

long long power(long long num, long long k) {
    if (!k) {
        return 1;
    }

    long long tmp = power(num, k / 2);
    if (k & 1) {
        return tmp * tmp % MOD * num % MOD;
    }
    return tmp * tmp % MOD;
}

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> p[i].a;
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i].b;
    }

    sort(p + 1, p + n + 1, cmp);

    long long sum = 0;
    long long tmp = 0;
    dp[0] = 1;
    dp2[0] = 1;
    for (int i = 1; i <= n; i++) {
        sum = (sum + i) % MOD;
        tmp = (tmp + i + 1) % MOD;
        dp[i] = dp[i - 1] * sum % MOD;
        dp2[i] = dp2[i - 1] * (sum + i) % MOD;
    }

    long long result = 0;
    sum = 0;
    for (int i = 1; i <= n; i++) {
        g[i] = dp2[n - 2] * power(dp2[i - 2], MOD - 2) % MOD * dp[i - 2] % MOD;
        result = (result + g[i] * p[i].b) % MOD;
        sum = (sum + g[i]) % MOD;
    }

    cout << result * power(sum, MOD - 2) % MOD << endl;

	return 0;
}