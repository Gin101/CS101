#include <iostream>

using namespace std;

int x = 0;
int a[3][4][4] = {{{0}}};
int b[15][15] = {{0}};
int c[4][4] = {{0}};

void ope(int idx) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            c[i][j] = a[idx][j][3 - i];
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            a[idx][i][j] = c[i][j];
        }
    }
}
void dfs(int idx) {
    if (idx == 3) {
        for (int i = 4; i <= 7; i++) {
            for (int j = 4; j <= 7; j++) {
                if (b[i][j] != 1) {
                    return;
                }
            }
        }
        cout << "Yes" << endl;
        exit(0);
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 7; j++) {
            for (int k = 1; k <= 7; k++) {
                for (int l = 0; l < 4; l++) {
                    for (int m = 0; m < 4; m++) {
                        b[j + l][k + m] += a[idx][l][m];
                    }
                }
                dfs(idx + 1);
                for (int l = 0; l < 4; l++) {
                    for (int m = 0; m < 4; m++) {
                        b[j + l][k + m] -= a[idx][l][m];
                    }
                }
            }
        }
        ope(idx);
    }
}
int main()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                char c;
                cin >> c;

                x += a[i][j][k] = (c == '#');
            }
        }
    }

    if (x == 16) {
        dfs(0);
    } 
    cout << "No" << endl;

    return 0;
}