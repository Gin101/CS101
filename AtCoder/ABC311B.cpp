#include <iostream>
#include <algorithm>

using namespace std;

const int maxND = 100;
char c[maxND][maxND];

int main()
{
    int n = 0;
    int d = 0;
    cin >> n >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cin >> c[i][j];
        }
    }

    int result = 0;
    int tmp = 0;
    for (int i = 0; i < d; i++) {
        bool flag = false;
        for (int j = 0; j < n; j++) {
            if (c[j][i] == 'x') {
                flag = true;
                result = max(result, tmp);
                tmp = 0;
                break;
            }
        }
        if (!flag) {
            tmp++;
        }
    }

    result = max(result, tmp);
    cout << result << endl;

    return 0;
}