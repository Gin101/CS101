#include <iostream>
#include <algorithm>

using namespace std;

const int maxM = 4e4;

struct Magic {
    long long val = 0;
    int idx = 0;
} x[maxM];
int a[maxM] = {0};
int b[maxM] = {0};
int c[maxM] = {0};
int d[maxM] = {0};

bool cmp(Magic x, Magic y) {
    return x.val < y.val;
}

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> x[i].val;
        x[i].idx = i;
    }

    sort(x, x + m, cmp);

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                for (int l = k + 1; l < m; l++) {
                    if (x[j].val - x[i].val == 2 * (x[l].val - x[k].val) && (x[j].val - x[i].val) * 3 < (x[k].val - x[j].val)) {
                        a[x[i].idx]++;
                        b[x[j].idx]++;
                        c[x[k].idx]++;
                        d[x[l].idx]++;

                        // cout << x[i].val << ' ' << x[j].val << ' ' << x[k].val << ' ' << x[l].val << endl;
                    } 
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        cout << a[i] << ' ' << b[i] << ' ' << c[i] << ' ' << d[i] << endl;
    }

    return 0;
}