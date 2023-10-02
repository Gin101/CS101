#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;

const int maxN = 1e5;
struct Water {
    int x = 0;
    int y = 0;
} water[maxN];

bool cmp(Water x, Water y) {
    return x.x < y.x;
}

queue<Water> q;
int main()
{
    int n = 0;
    int d = 0;
    cin >> n >> d;

    for (int i = 0; i < n; i++) {
        cin >> water[i].x >> water[i].y;
    }

    sort(water, water + n, cmp);

    int result = INT_MAX;
    for (int i = 0; i < n; i++) {
        while (q.size() > 1 && abs(q.front().y - water[i].y) >= d) {
            result = min(result, abs(q.front().x - water[i].x));
            q.pop();
        }
        q.push(water[i]);
    }

    if (result == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}