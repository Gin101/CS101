#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 2e5 + 1;

int n = 0;
int m = 0;
int k = 0;
long long pre[maxN] = {0};
int a[maxN] = {0};
long long result = 0;
void dfs(int l, int r) {
    if (l == r) {
        result += (a[l] >= 0);
        return;
    }

    int mid = (l + r) / 2;
    dfs(l, mid);
    dfs(mid + 1, r);
    int idx = 0;
    pre[idx] = 0;
    for (int i = mid + 1; i <= r; i++) {
        idx++;
        pre[idx] = pre[idx - 1] + a[i];
    }

    sort(pre + 1, pre + idx + 1);
    long long sum = 0;
    for (int i = mid; i >= l ;i--) {
        sum += a[i];
        int tmp = lower_bound(pre + 1, pre + idx + 1, -sum) - pre;
        result += max(0, idx - tmp + 1);
    }
}

int main()
{
    int n = 0;
    int k = 0;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= k;
    }

    dfs(1, n);
    cout << result << endl;

    return 0;
}