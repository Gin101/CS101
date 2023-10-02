#include <iostream>

using namespace std;

const int maxNM = 100;
char c[maxNM][maxNM];
char result[maxNM][maxNM];

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    int idx = 0;
    int idx2 = 0;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c[i][j];

            if (flag && c[i][j] == '.') {
                result[i][j] = 'B';
                idx = i;
                idx2 = j;
                flag = false;
            }
        }
    }

    for (int i = idx; i < n; i++) {
        for (int j = idx2; j < m; j++) {
            if (i == idx && j == idx2) {
                continue;
            } else if (j == idx2) {
                if (result[i - 1][j] == 'B') {
                    result[i][j] = 'W';
                } else {
                    result[i][j] = 'B';
                }
            } else {
                if (result[i][j - 1] == 'B') {
                    result[i][j] = 'W';
                } else {
                    result[i][j] = 'B';
                }
            }
        }
    }
    for (int i = idx; i >= 0; i--) {
        for (int j = idx2; j >= 0; j--) {
            if (i == idx && j == idx2) {
                continue;
            } 
            if (result[i][j + 1] == 'B') {
                result[i][j] = 'W';
            } else {
                result[i][j] = 'B';
            }
        }
    }

    for (int i = idx + 1; i < n; i++) {
        for (int j = idx2; j >= 0; j--) {
            if (result[i][j + 1] == 'B') {
                result[i][j] = 'W';
            } else {
                result[i][j] = 'B';
            }
        }
    }

    for (int i = idx; i >= 0; i--) {
        for (int j = idx2 + 1; j < m; j++) {
            if (result[i + 1][j] == 'B') {
                result[i][j] = 'W';
            } else {
                result[i][j] = 'B';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[i][j] == '.') {
                cout << result[i][j];
            } else {
                cout << '-';
            }
        }
        cout << endl;
    }

    return 0;
}