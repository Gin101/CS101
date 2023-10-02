#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 2e5 + 1;
int a[maxN] = {0};
int idx[maxN] = {0};
long long num[maxN] = {0};
long long sum[maxN] = {0};
long long sum2[maxN] = {0};
int main()
{
    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int cnt = 1;
    int tmp = 1;
    for (int i = 1; i <= n; i++) {
        while (cnt <= n && a[cnt] >= cnt - i + 1) {
            num[cnt++] = i;
        }
        tmp = min(max(tmp, cnt + 1), n + 1);
        while (tmp <= n && a[tmp] >= tmp - i + 1) {
            tmp++;
        }
        if (idx[cnt] == 0) {
            idx[cnt] = i;
        }
        sum[i] = sum[i - 1] + (cnt - i);
        sum2[i] = sum2[i - 1] + (tmp - i);
    }
	
    int m = 0;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int x = 0;
        int y = 0;
        cin >> x >> y;

        long long result = sum[n];
        if (a[x] > y && num[x] <= x - y) {
            result = sum[n] - (sum[x - y] - sum[num[x] - 1]) + (x - num[x] + y) * (x - num[x] - y + 1) / 2;
        } else if (a[x] < y && idx[x]) {
            result = (sum[n] - (sum[num[x] - 1] - sum[max(x - y, idx[x] - 1)]) + sum2[num[x] - 1] - sum2[max(x - y, idx[x] - 1)]);
        }

        cout << result << endl;
    }
	
    return 0;
}