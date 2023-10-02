#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 100;
int a[maxN] = {0};

int main()
{
    int n = 0;
    int k = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = k; i < n; i++) {
        cout << a[i] << ' ';
    }
    for (int i = 0; i < min(k, n); i++) {
        cout << 0 << ' ';
    }
    cout << endl;

    return 0;
}