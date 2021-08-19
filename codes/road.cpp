#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxN = 10;
int list[maxN][maxN] = {0};

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> list[i][j];
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            list[i][j] += min(list[i + 1][j], list[i + 1][j + 1]);
        }
    }

    cout << list[0][0] << endl;

    return 0;
}