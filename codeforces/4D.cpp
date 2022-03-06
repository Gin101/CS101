#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 5001;
int n = 0;
int w[maxN] = {0};
int h[maxN] = {0};
int _next[maxN] = {0};
int result[maxN] = {0};
int dp(int idx) {
    if (result[idx]) {
        return result[idx];
    }

    result[idx] = 1;
    for (int i = 0; i <= n; i++) {
        if (w[i] > w[idx] && h[i] > h[idx]) {
            if (dp(i) + 1 > result[idx]) {
                _next[idx] = i;
                result[idx] = result[i] + 1;
            }
        }
    }

    return result[idx];
}

int main()
{
    cin >> n;

    for (int i = 0; i <= n; i++) {
        cin >> w[i] >> h[i];
    }

    memset(_next, -1, sizeof(_next));

    dp(0);

    cout << --result[0] << endl;

    int idx = _next[0];
    while (idx != -1) {
        cout << idx << ' ';
        idx = _next[idx];
    }

    cout << endl;

    return 0;
}
 