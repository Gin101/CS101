#include <iostream>

using namespace std;

const int maxN = 2e5 + 1;
long long sum[maxN] = {0};
long long tmp[maxN] = {0};
long long result = 0;
void dfs(int l, int r) {
    if (l == r) {
        if (sum[l] >= 0) {
            result++;
        }
        return;
    }
    int mid = (l + r) / 2;
    dfs(l, mid);
    dfs(mid + 1, r);
    int idx = mid + 1;
    int idx2 = l;
    for (int i = l; i <= r; i++) {
        if ((idx2 == mid + 1 || sum[idx2] > sum[idx]) && idx != r + 1) {
            tmp[i] = sum[idx++];
        } else {
            result += r - idx + 1;
            tmp[i] = sum[idx2++];
        }
    }

    for (int i = l; i <= r; i++) {
        sum[i] = tmp[i];
    }
}

int main()
{
    int n = 0;
    long long k = 0;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        long long a = 0;
        cin >> a;

        sum[i] = sum[i - 1] + a - k;
    }

    dfs(1, n);

    cout << result << endl;

    return 0;
}