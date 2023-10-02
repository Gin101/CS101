#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 1e5;
const int maxM = 1e5;
struct AB {
    int num = 0;
    int idx = 0;
} ab[maxN + maxM];

bool cmp(AB x, AB y) {
    return x.num < y.num;
}

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> ab[i].num;
        ab[i].idx = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> ab[n + i].num;
        ab[n + i].idx = n + i;
    }

    sort(ab, ab + n + m, cmp);

    for (int i = 0; i < n + m; i++) {
        if (ab[i].idx < n) {
            cout << i + 1 << ' ';
        }
    }
    cout << endl;
    for (int i = 0; i < n + m; i++) {
        if (ab[i].idx > n - 1) {
            cout << i + 1 << ' ';
        }
    }

    cout << endl;

    return 0;
}