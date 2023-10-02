#include <iostream>
#include <stdio.h>

using namespace std;

int a[8] = {0};

int main()
{
    freopen("sortcard.in", "r", stdin);
    freopen("sortcard.out", "w", stdout);

    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << 0 << endl;
    } else if (n == 2) {
        if (a[0] == 1) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
    }

    return 0;
}