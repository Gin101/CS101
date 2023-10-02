#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> se;
string a[10];

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (m == 1) {
        for (int i = 0; i < n; i++) {
            se.insert(a[i]);
        }
    } else if (m == 2) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == i) {
                    continue;
                }
                se.insert(a[i] + a[j]);
            }
        }
    } else if (m == 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == i) {
                    continue;
                }
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) {
                        continue;
                    }
                    se.insert(a[i] + a[j] + a[k]);
                }
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == i) {
                    continue;
                }
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) {
                        continue;
                    }
                    for (int l = 0; l < n; l++) {
                        if (l == i || l == j || l == k) {
                            continue;
                        }
                        se.insert(a[i] + a[j] + a[k] + a[l]);
                    }
                }
            }
        }
    }

    cout << se.size() << endl;

    return 0;
}