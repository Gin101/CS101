#include <iostream>

using namespace std;

const int maxN = 1000;
int f[maxN][maxN] = {0};

int main()
{
    int n = 0;
    int q = 0;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;

            if (c == '*') {
                f[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            f[i][j] += f[i][j - 1];
        }
    }

    for (int i = 0; i < q; i++) {
        int x1 = 0;
        int y1 = 0;
        int x2 = 0;
        int y2 = 0;
        cin >> x1 >> y1 >> x2 >> y2;

        int result = 0;
        while (x1 <= x2) {
            if (y1 - 1 > 0) {
                result += f[x1 - 1][y2 - 1] - f[x1 - 1][y1 - 2];
            } else {
                result += f[x1 - 1][y2 - 1];
            }
            x1++;
        }

        cout << result << endl;
    }

    return 0;
}