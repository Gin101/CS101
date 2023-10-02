#include <iostream>

using namespace std;

const int maxN = 2e5 + 1;
long long a[maxN] = {0};

int main()
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        int k = 0;
        cin >> n >> k;
        for (int j = 1; j <= n; j++) {
            cin >> a[j];
            a[j] += a[j - 1];
        }
        int l = k - 1;
        int r = k;
        long long maxA = a[l];
        long long result = a[r];
        while (0 < l && r < n) {
            if (a[l - 1] <= result) {
                maxA = min(maxA, a[--l]);
            } else if (maxA <= a[r + 1]) {
                result = max(result, a[++r]);
            } else {
                break;
            }
        }
        if (0 < l && r < n) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
	
	return 0;
}