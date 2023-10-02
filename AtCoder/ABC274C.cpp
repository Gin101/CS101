#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 2e5 + 1;
int a[maxN] = {0};
int amo[maxN * 3] = {0};

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        amo[i * 2] = amo[a[i]] + 1;
        amo[i * 2 + 1] = amo[a[i]] + 1;
    }

    for (int i = 1; i <= 2 * n + 1; i++) {
        cout << amo[i] << endl;
    }

    return 0;
}