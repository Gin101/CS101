#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 100;
char num[maxN][maxN] = {{0}};
char result[maxN][maxN] = {{0}};

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> num[i][j];
        }
    }

    memcpy(result, num, sizeof(result));

    for (int i = 1; i < n; i++) {
        result[0][i] = num[0][i - 1];
        result[i][n - 1] = num[i - 1][n - 1];
    }
    for (int i = n - 2; i >= 0; i--) {
        result[n - 1][i] = num[n - 1][i + 1];
        result[i][0] = num[i + 1][0];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j];
        }
        cout << endl;
    }

    return 0;
}