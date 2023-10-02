#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

const int maxN = 1e5 + 1;
int a[maxN] = {0};
int main() 
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    int l = INT_MIN;
    int r = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        l = max(l, a[i]);
        r += a[i];
    }

    while (l <= r) {
        int mid = (l + r) / 2;
        int cnt = 0;
        int num = 0;

        for (int i = 1; i <= n; i++) {
            if (num + a[i] <= mid) {
                num += a[i];
            } else {
                num = a[i];
                cnt++;
            }
        }

        if (cnt >= m) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << l << endl;

    return 0;
}