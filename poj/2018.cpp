#include <iostream>
#include <algorithm>

using namespace std;

int n = 0;
int f = 0;
const int maxN = 1e5 + 1;
double field[maxN] = {0};
double sum[maxN] = {0};
double num[maxN] = {0};

bool check(double x) {
    for (int i = 1; i <= n; i++) {
        num[i] = field[i] - x;
    }

    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + num[i];
    }

    double tmp3 = 1e10;
    double result = -1e10;
    for (int i = f; i <= n; i++) {
        tmp3 = min(tmp3, sum[i - f]);
        result = max(result, sum[i] - tmp3);
    }

    return result >= 0;
}

int main()
{
    cin >> n >> f;

    for (int i = 1; i <= n; i++) {
        cin >> field[i];
    }

    double l = -1;
    double r = 2000;
    double tmp = 1e-4;
    while (r - l > tmp) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << (int)(r * 1000) << endl;

    return 0;
}