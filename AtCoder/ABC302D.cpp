#include <iostream>
#include <algorithm>

using namespace std;

const int maxNM = 2e5;
long long a[maxNM] = {0};
long long b[maxNM] = {0};

int main()
{
    int n = 0;
    int m = 0;
    long long d = 0;
    cin >> n >> m >> d;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + m);

    n--;
    m--;
    while (n >= 0 && m >= 0) {
        if (a[n] > b[m]) {
            if (a[n] - b[m] > d) {
                n--;
            } else {
                cout << a[n] + b[m] << endl;
                return 0;
            }
        } else {
            if (b[m] - a[n] > d) {
                m--;
            } else {
                cout << b[m] + a[n] << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;

    return 0;
}