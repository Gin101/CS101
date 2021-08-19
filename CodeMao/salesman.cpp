#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int maxN = 1e5;
struct House {
    int s = 0;
    int a = 0;
} h[maxN];

int now = 0;
bool operator< (House x, House y) {
    x.s = max(x.s - now, 0);
    y.s = max(y.s - now, 0);

    int tmp = 2 * x.s + x.a;
    int tmp2 = 2 * y.s + y.a;

    return tmp < tmp2;
}

priority_queue <House> q;

int main()
{   
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> h[i].s;
    }

    for (int i = 0; i < n; i++) {
        cin >> h[i].a;
    }

    for (int i = 0; i < n; i++) {
        q.push(h[i]);
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        int tmp = max(q.top().s - now, 0);
        result += tmp * 2 + q.top().a;
        now = max(tmp, now);
        q.pop();

        priority_queue <House> q2;

        while (!q.empty()) {
            House tmp2 = q.top();
            tmp2.s = max(q.top().s - now, 0);
            q2.push(tmp2);
            q.pop();
        }

        q = q2;

        cout << result << endl;
    }

    return 0;
}