#include <iostream>
#include <algorithm>

using namespace std;

const int maxIdx = 8e5 + 1;
const int INF = 4e5 + 1;
int r[maxIdx] = {0};
int c[maxIdx] = {0};
struct Rec {
    int tmp = 0;
    int x = 0;
    int y = 0;
    int flag = 0;
} s[maxIdx], t[maxIdx];

bool cmp(Rec x, Rec y) {
    return x.tmp == y.tmp ? x.flag > y.flag : x.tmp < y.tmp;
}
int main()
{
    int n = 0;
    cin >> n;

    int idx = 0;
    for (int i = 1; i <= n; i++) {
        int xr = 0;
        int xc = 0;
        int yr = 0;
        int yc = 0;
        cin >> xr >> xc >> yr >> yc;

        s[++idx].tmp = xr;
        s[idx].x = xc;
        s[idx].y = yc;
        s[idx].flag = 1;
        t[idx].tmp = xc;
        t[idx].x = xr;
        t[idx].y = yr;
        t[idx].flag = 1;
        s[++idx].tmp = yr;
        s[idx].x = xc;
        s[idx].y = yc;
        s[idx].tmp = yc;
        s[idx].x = xr;
        s[idx].y = yr;
    }

    sort(s + 1, s + idx + 1, cmp);
    sort(t + 1, t + idx + 1, cmp);

    int result = 0;
    for (int i = 1; i <= idx; i++) {
        if (s[i].flag) {
            for (int j = s[i].x; j < s[i].y; j++) {
                if (!r[j + INF]) {
                    result++;
                    r[j + INF]++;
                }
            }
        } else {
            for (int j = s[i].x; j < s[i].y; j++) {
                r[j + INF]--;
                if (!r[j + INF]) {
                    result++;
                }
            }
        }

        if (t[i].flag) {
            for (int j = t[i].x; j < t[i].y; j++) {
                if (!c[j + INF]) {
                    result++;
                    c[j + INF]++;
                }
            }
        } else {
            for (int j = t[i].x; j < t[i].y; j++) {
                c[j + INF]--;
                if (!c[j + INF]) {
                    result++;
                }
            }
        }
    }

    cout << result << endl;

    return 0;
}