#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

const int maxN = 2e5;
bool flag[maxN] = {false};
int p[maxN] = {0};
int result[maxN] = {0};
int tmp[maxN] = {0};

int main()
{
    int n = 0;
    int k = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    memset(result, -1, sizeof(result));
    int tmp2 = n;
    for (int i = 0; i < n; i++) {
        if (!flag[i]) {
            memset(tmp, 0, sizeof(tmp));
            tmp[0] = p[i];
            int cnt = 0;
            int idx = n;
            for (int j = i + 1; j < n; j++) {
                if (cnt == k - 1) {
                    idx = j;
                    break;
                }
                if (!flag[j] && p[j] < tmp[cnt]) {
                    flag[j] = true;
                    tmp[++cnt] = p[j];
                }
            }

            if (cnt == k - 1) {
                for (int j = 0; j <= cnt; j++) {
                    result[tmp[j] - 1] = idx;
                }
            }

            while (flag[n - 1]) {
                n--;
            }
        }
    }

    for (int i = 0; i < tmp2; i++) {
        cout << result[i] << endl;
    }

    return 0;
}