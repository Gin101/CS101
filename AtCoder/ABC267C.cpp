#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

const int maxN = 2e5 + 1;
long long a[maxN] = {0};
long long sum[maxN] = {0};
long long sum2[maxN] = {0};

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        sum2[i] = sum2[i - 1] + a[i] * i;
    }

    long long result = LONG_MIN;
    for (int i = 0; i <= n - m; i++) {
        result = max(result, sum2[i + m] - sum2[i] - (sum[i + m] - sum[i]) * i);
    }

    cout << result << endl;

    return 0;
}