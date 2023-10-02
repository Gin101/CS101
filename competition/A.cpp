#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 2e7 + 2;
const int maxM = 2e7 + 2;
int pre[maxN] = {0};
int _next[maxN] = {0};
long long val[maxN] = {0};
long long sum[maxN] = {0};
long long sum2[maxN] = {0};
long long maxSum[maxN] = {0};
long long maxSum2[maxN] = {0};
int main() 
{
    int n = 0;
    int k = 0;
    int m = 0;
    cin >> n >> k >> m;

    string s;
    string s2;
    cin >> s >> s2;

    int idx = 0;
    for (int i = 1; i <= n; i++) {
        pre[++idx] = idx - 1;
        _next[idx] = idx + 1;
        val[idx] = s[i - 1] - 'm';
    }

    for (int i = 1; i <= n; i++) {
        sum[i] = max(val[i], sum[i - 1] + val[i]);
        maxSum[i] = max(sum[i], maxSum[i - 1]);
    }
    for (int i = n; i >= 1; i--) {
        sum2[i] = max(val[i], sum2[i + 1] + val[i]);
        maxSum2[i] = max(sum2[i], maxSum2[i + 1]);
    }

    long long result = 0;
    k--;
    for (int i = 1; i <= m * 2; i += 2) {
        long long tmp = 0;
        if (s2[i - 1] == '1') {
            sum2[pre[k]] = max(val[pre[k]], sum2[k] + val[pre[k]]);
            maxSum2[pre[k]] = max(maxSum2[k], sum2[pre[k]]);
            k = pre[k];
            tmp = max(sum[k] + sum2[_next[k]], max(maxSum[k], maxSum2[_next[k]]));
        } else if (s2[i - 1] == '2') {
            sum[_next[k]] = max(val[_next[k]], sum[k] + val[_next[k]]);
            maxSum[_next[k]] = max(maxSum[k], sum[_next[k]]);
            k = _next[k];
            tmp = max(sum[k] + sum2[_next[k]], max(maxSum[k], maxSum2[_next[k]]));
        } else {
            _next[++idx] = _next[k];
            pre[_next[k]] = idx;
            pre[idx] = k;
            _next[k] = idx;
            val[idx] = s2[i] - 'm';
            k = _next[k];
            sum[k] = max(val[k], sum[pre[k]] + val[k]);
            sum2[k] = max(val[k], sum2[_next[k]] + val[k]);
            maxSum[k] = max(maxSum[pre[k]], sum[k]);
            maxSum2[k] = max(maxSum2[k], sum2[k]);
            k = pre[k];
            tmp = max(sum[k] + sum2[_next[k]], max(maxSum[k], maxSum2[_next[k]]));
            k = _next[k];
            tmp = max(sum[k] + sum2[_next[k]], max(maxSum[k], maxSum2[_next[k]]));
        }
        result ^= tmp * (i + 1) / 2;
    }

    cout << result << endl;

	return 0;
}