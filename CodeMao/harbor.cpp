#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct People {
    int idx = 0;
    int c = 0;
} p;

queue <People> q;
queue <People> tmp;
const int maxX = 1e5;
bool flag[maxX] = {false};

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        memset(flag, false, sizeof(flag));

        int t = 0;
        int k = 0;
        cin >> t >> k;

        for (int j = 0; j < k; j++) {
            cin >> p.c;

            p.idx = t;

            q.push(p);
        }

        while (t - 86400 >= q.front().idx) {
            q.pop();
        }

        int result = 0;
        while (!q.empty()) {
            if (!flag[q.front().c - 1]) {
                flag[q.front().c - 1] = true;
                result++;
            }

            tmp.push(q.front());
            q.pop();
        }

        while (!tmp.empty()) {
            q.push(tmp.front());
            tmp.pop();
        }

        cout << result << endl;
    }

    return 0;
}