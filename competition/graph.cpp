#include <iostream>
#include <stdio.h>

using namespace std;

const int maxN = 2020;
char c[maxN][maxN] = {{0}};

int main()
{
    freopen("graph.in", "r", stdin);
    freopen("graph.out", "w", stdout);

    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cin >> c[j][k];
            }
        }

        if (n % 2 == 0) {
            cout << "T" << endl;
        } else {
            cout << "N" << endl;
        }
    }

    return 0;
}