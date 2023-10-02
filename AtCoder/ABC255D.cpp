#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxN = 2e5;
long long a[maxN] = {0};
long long sum[maxN] = {0};

int main()
{
    int n = 0;
    int q = 0;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);
    
    sum[0] = a[0];
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    
    for (int i = 0; i < q; i++) {
        long long x = 0;
        cin >> x;

        long long l = -1;
        long long r = n;
        while (r - l > 1) {
            if (a[l + (r - l) / 2] > x) {
                r = l + (r - l) / 2;
            } else {
                l = l + (r - l) / 2;
            }
        }

        cout << x * r * 2 - sum[r - 1] * 2 + sum[n - 1] - x * n << endl;
    }

    return 0;
}