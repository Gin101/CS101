#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>

using namespace std;

int gcd(int x, int y) {
	if (y == 0) {
        return x;
    }
	return gcd(y, x % y);
}

const int maxNM = 3e5;
int li[maxNM] = {0};
bool flag[maxNM] = {false};
int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    int idx = 1;
    for (int i = 1; i <= n; i++) {
        int tmp = 0;
        cin >> tmp;

        li[idx++] = tmp;
        for (int j = 1; j <= m; j++) {
            if (tmp - j >= 0 && !flag[tmp - j]) {
                li[idx] = tmp - j;
                flag[li[i] - j] = true;
                idx++;
            }
        }
    }

    idx--;
    int result = INT_MAX;
    for (int i = 1; i <= idx; i++) {
        result = min(result, li[i]);
    }

    int tmp = gcd(li[1], li[2]);
    for (int i = 3; i <= idx; i++) {
        tmp = gcd(tmp, li[i]);
    }
    if (tmp > 1 || result == 1) {
        cout << -1 << endl;
        return 0;
    }

    memset(flag, false, sizeof(flag));
    flag[0] = true;
    int idx2 = 0;
    int cnt = 0;
    while (idx2 < result) {
        if (flag[cnt]) {
            for (int i = 1; i <= idx; i++) {
                flag[cnt + li[i]] = true;
            } 
            idx2++;
        } else {
            idx2 = 0;
        }
        cnt++;
    }

    cout << cnt - result - 1 << endl;

    return 0;
}