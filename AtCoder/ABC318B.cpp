#include <iostream>

using namespace std;

const int maxN = 100;
bool flag[maxN][maxN] = {{false}};

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a = 0;
        int b = 0;
        int c = 0;
        int d = 0;
        cin >> a >> b >> c >> d;

        for (int j = a; j < b; j++) {
            for (int k = c; k < d; k++) {
                flag[j][k] = true;
            }
        }
    }

    int result = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (flag[i][j]) {
                result++;
            }
        }
    }

    cout << result << endl;

    return 0;
}