#include <iostream>
#include <limits.h>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxK = 1000;
const int maxN = 1000;
int a[maxK] = {0};
long long x[maxN] = {0};
long long y[maxN] = {0};
bool flag[maxK] = {false};
int main()
{
	int n = 0;
    int k = 0;
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        cin >> a[i];
        flag[a[i] - 1] = true;
    }

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    long long result = 0;
    for (int i = 0; i < n; i++) {
        if (!flag[i]) {
            long long tmp = LONG_MAX;
            for (int j = 0; j < k; j++) {
                tmp = min(tmp, (x[i] - x[a[j] - 1]) * (x[i] - x[a[j] - 1]) + (y[i] - y[a[j] - 1]) * (y[i] - y[a[j] - 1]));
            }
            result = max(result, tmp);
        }
    }

	cout << double(sqrt(result)) << endl;

    return 0;
}