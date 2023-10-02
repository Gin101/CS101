#include <iostream>

using namespace std;

const int maxM = 2e5;
int a[maxM] = {0};

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    int idx = 0;
    for (int i = 1; i <= n; i++) {
        if (i < a[idx]) {
            cout << a[idx] - i << endl;
        } else if (i == a[idx]) {
            cout << 0 << endl;
            idx++;
        }
    }

    return 0;
}