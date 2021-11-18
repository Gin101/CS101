#include <iostream>

using namespace std;

const int maxN = 39;
int result[maxN][maxN] = {{0}};
struct Number {
    int row = 0;
    int col = 0;
} box[maxN * maxN];

int main()
{
    int n = 0;
    cin >> n;

    int cnt = 1;
    result[0][n / 2] = cnt++;
    box[cnt - 2].row = 0;
    box[cnt - 2].col = n / 2;
    while (cnt <= n * n) {
        if (box[cnt - 2].row == 0 && box[cnt - 2].col != (n - 1)) {
            result[n - 1][box[cnt - 2].col + 1] = cnt;
            cnt++;
            box[cnt - 2].row = n - 1;
            box[cnt - 2].col = box[cnt - 3].col + 1;
        } else if (box[cnt - 2].row != 0 && box[cnt - 2].col == (n - 1)) {
            result[box[cnt - 2].row - 1][0] = cnt;
            cnt++;
            box[cnt - 2].row = box[cnt - 3].row - 1;
            box[cnt - 2].col = 0;
        } else if (box[cnt - 2].row == 0 && box[cnt - 2].col == (n - 1)) { 
            result[box[cnt - 2].row + 1][n - 1] = cnt;
            cnt++;
            box[cnt - 2].row = box[cnt - 3].row + 1;
            box[cnt - 2].col = n - 1;
        } else {
            if (result[box[cnt - 2].row - 1][box[cnt - 2].col + 1] == 0) {
                result[box[cnt - 2].row - 1][box[cnt - 2].col + 1] = cnt;
                cnt++;
                box[cnt - 2].row = box[cnt - 3].row - 1;
                box[cnt - 2].col = box[cnt - 3].col + 1;
            } else {
                result[box[cnt - 2].row + 1][box[cnt - 2].col] = cnt;
                cnt++;
                box[cnt - 2].row = box[cnt - 3].row + 1;
                box[cnt - 2].col = box[cnt - 3].col;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            cout << result[i][j] << ' ';
        }
        cout << result[i][n - 1] << endl;
    }

    return 0;
}