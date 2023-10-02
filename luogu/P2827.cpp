#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

const int maxN = 7e6 + 1;
priority_queue<int> result;
int cut1[maxN] = {0};
int cut2[maxN] = {0};
int now[maxN] = {0};

int main()
{
    int n = 0;
    int m = 0;
    int q = 0;
    int u = 0;
    int v = 0;
    int t = 0;
    cin >> n >> m >> q >> u >> v >> t;
    double p = (double)u / v;

    for (int i = 1; i <= n; i++) {
        cin >> now[i];
    }


    int t0 = n;
    int t1 = 0;
    int t2 = 0;
    int h = 1;
    int h1 = 1;
    int h2 = 1;

    sort(now + 1, now + t0 + 1, greater<int>());

    int top = 0;
    int sum = 0;
    for (int i = 1; i <= m; i++) {
        if (h > t0) {
            if (cut1[h1] > cut2[h2]) {
                top = cut1[h1++];
            } else {
                top = cut2[h2++];
            }
        } else if (now[h] >= cut1[h1] && now[h] >= cut2[h2]) {
            top = now[h];
            h++;
        } else if (cut1[h1] >= cut2[h2] && now[h] <= cut1[h1]) {
            top = cut1[h1];
            h1++;
        } else {
            top = cut2[h2];
            h2++;
        }

        top += sum;
        int a1 = floor(p * (double)top);
        int a2 = top - a1;
        sum += q;
        a1 -= sum;
        a2 -= sum;
        cut1[++t1] = a1;
        cut2[++t2] = a2;
        if (i % t == 0) {
            cout << top << ' ';
        }
    }

    cout << endl;
    for (int i = h; i <= t0; i++) {
        result.push(now[i]);
    }
    for (int i = h1; i <= t1; i++) {
        result.push(cut1[i]);
    }
    for (int i = h2; i <= t2; i++) {
        result.push(cut2[i]);
    }

    for (int i = 1; !result.empty(); i++) {
        if (i % t == 0) {
            cout << result.top() + sum << ' ';
        }
        result.pop();
    }

    cout << endl;

    return 0;
}