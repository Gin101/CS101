#include <iostream>
#include <cstring>

using namespace std;

int n = 0;
const int maxN = 100;
int a[maxN][maxN] = {{0}};
int b[maxN][maxN] = {{0}};
int pre[maxN][maxN] = {{0}};

bool check() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1 && b[i][j] != 1) {
                return true;
            }
        }
    }

    cout << "Yes" << endl;
    exit(0);
}
int main()
{
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }

    int cnt = 0;
    while (cnt < 4 && check()) {
        memcpy(pre, a, sizeof(pre));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = pre[n - 1 - j][i];
            }
        }
        cnt++;
    }
    cout << "No" << endl;

    return 0;
}