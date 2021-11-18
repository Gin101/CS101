#include <iostream>
#include <stdio.h>

using namespace std;

const int maxM = 1e6;
const int maxN = 1e6;
int a[maxM] = {0};
int b[maxN] = {0};

int main()
{
    freopen("intersection.in", "r", stdin);
    freopen("intersection.out", "w", stdout);

    int m = 0;
    int n = 0;
    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int idxa = 0;
    int idxb = 0;

    while (idxa != n - 1 && idxb != n - 1) {
        if (a[idxa] > b[idxb]) {
            idxb++;
        } else if (a[idxa] < b[idxb]) {
            idxa++;
        } else {
            cout << a[idxa] << ' ';
            idxa++;
            idxb++;
        }
    }

    cout << endl;

    return 0;
}