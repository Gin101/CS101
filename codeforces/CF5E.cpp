#include <iostream>

using namespace std;

const int maxN = 1e6 + 1;
int h[maxN] = {0};
int box[maxN] = {0};
long long num[maxN] = {0};
int st[maxN] = {0};
int main()
{
    int n = 0;
    cin >> n;

    int idx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        if (h[i] > h[idx]) {
            idx = i;
        }
    }

    int cnt = 0;
    for (int i = idx + 1; i <= n; i++) {
        box[++cnt] = h[i];
    }
    for (int i = 1; i <= idx - 1; i++) {
        box[++cnt] = h[i];
    }

    long long result = n - 1;
    idx = 0;
    for (int i = 1; i <= cnt; i++) {
        while (idx && st[idx] < box[i]) {
            result += num[idx--];
        }
        if (st[idx] != box[i]) {
            st[++idx] = box[i];
            num[idx] = 0;
        }
        result += num[idx]++;
    }
    while (idx > 1) {
        result += num[idx--];
    }
    cout << result << endl;

    return 0;
}