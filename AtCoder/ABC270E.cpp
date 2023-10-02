#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 1e5;
long long a[maxN] = {0};

int main()
{
    int n = 0;
    long long k = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long l = 0;
    long long r = k + 1;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += min(a[i], mid);
        }
        if (sum > k) {
            r = mid;
        } else {
            l = mid;
        }
    }
    for (int i = 0; i < n; i++) {
        k -= min(a[i], l);
        a[i] -= min(a[i], l);
    }
    
    int idx = 0;
    while (k > 0) {
        if (a[idx] > 0) {
            a[idx]--;
            k--;
        }
        idx++;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;

    return 0;
}