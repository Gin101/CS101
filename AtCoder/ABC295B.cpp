#include <iostream>
#include <algorithm>

using namespace std;

const int maxR = 20;
const int maxC = 20;
char b[maxR][maxC] = {{0}};

int main()
{
    int r = 0;
    int c = 0;
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (b[i][j] > 48 && b[i][j] < 58) {
                b[i][j] -= 48;
                for (int k = max(0, i - b[i][j]); k <= min(r - 1, i + b[i][j]); k++) {
                    int tmp = k - i + b[i][j];
                    if (tmp < b[i][j] + 1) {
                        for (int l = max(0, j - tmp); l <= min(c - 1, j + tmp); l++) {
                            if (b[k][l] == '#') {
                                b[k][l] = '.';
                            }
                        }
                    } else {
                        for (int l = tmp - j; l <= 3 * j - tmp ; l++) {
                           if (b[k][l] == '#') {
                                b[k][l] = '.';
                            } 
                        }
                    }
                }
                b[i][j] = '.';
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << b[i][j];
        }
        cout << endl;
    }

    return 0;
}