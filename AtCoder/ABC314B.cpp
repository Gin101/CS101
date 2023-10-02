#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 100;
const int maxC = 37;
int a[maxN][maxC] = {{0}};
int c[maxN] = {0};

struct People {
    int idx = 0;
    int cnt = 0;
} result[maxN];

bool cmp(People x, People y) {
    return x.cnt == y.cnt ? x.idx < y.idx : x.cnt < y.cnt;
}

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> c[i];

        for (int j = 0; j < c[i]; j++) {
            cin >> a[i][j]; 
        }
    }

    int x = 0;
    cin >> x;

    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < c[i]; j++) {
            if (a[i][j] == x) {
                result[idx].cnt = c[i];
                result[idx].idx = i;
                idx++;
            }
        }
    }

    sort(result, result + idx, cmp);

    if (idx == 0) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 1; i < idx; i++) {
        if (result[i].cnt != result[i - 1].cnt) {
            cout << i << endl;
            for (int j = 0; j < i; j++) {
                cout << result[j].idx + 1 << ' ';
            }
            cout << endl;
            return 0;
        }
    }

    cout << idx << endl;
    for (int i = 0; i < idx; i++) {
        cout << result[i].idx + 1 << ' ';
    }
    cout << endl;

    return 0;
}