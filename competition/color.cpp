#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool flag[26] = {false};

int main()
{
    int n = 0;
    string s;
    cin >> n >> s;

    double result = 1.0;
    int l = 0;
    int r = 0;
    for (double i = 0; i < n; i++) {
        for (double j = i; j < n; j++) {
            double cnt = 0;
            memset(flag, false, sizeof(flag));
            for (int k = i; k <= j; k++) {
                if (!flag[s[k] - 97]) {
                    cnt++;
                }
                flag[s[k] - 97] = true;
            }

            if (i == j && result == 1) {
                l = i + 1;
                r = j + 1;
            } else if (cnt / (j - i) < result) {
                result = cnt / (j - i);
                l = i + 1;
                r = j + 1;
            }
        }
    }

    cout << l << ' ' << r << endl;

    return 0;
}