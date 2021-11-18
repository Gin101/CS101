#include <iostream>
#include <limits.h>

using namespace std;

const int maxN = 2e5;
int t[maxN] = {0};
int cnt[maxN] = {0};
bool flag[maxN] = {false};

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> t[i];
        cnt[t[i] - 1]++;
    }

    bool flag2 = false;
    do {
        flag2 = false;
        for (int i = 0; i < n; i++) {
            if (cnt[i] == 0 && !flag[i]) {
                cnt[t[i] - 1]--;
                flag2 = true;
                flag[i] = true;
            }
        }
    } while (flag2);

    int result = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (cnt[i] > 0) {
            int now = i;
            int tmp = 1;
            while (t[now] - 1 != i) {
                now = t[now] - 1;
                tmp++;
            }
            result = min(result, tmp);
        }
    }

    cout << result << endl;

    return 0;
}