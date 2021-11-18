#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int maxN = 1e6;
bool flag[maxN] = {false};
queue<int> q;
queue<int> dp;
int main()
{
    int t = 0;
    cin >> t;


    for (int i = 0; i < t; i++) {
        int n = 0;
        int d = 0;
        cin >> n >> d;

        memset(flag, false, sizeof(flag));
        for (int i = 0; i < n; i++) {
            cin >> flag[i];
        }

        for (int i = 0; i < n; i++) {
            if (!flag[i]){
                q.push(i);
            }
        }

        int result = 0;
        while (!q.empty()) {
            while (!q.empty()) {
                int tmp = q.front();
                q.pop();
                if (flag[(tmp + d) % n]) {
                    flag[(tmp + d) % n] = false;
                    dp.push((tmp + d) % n);
                }
            }

            while (!dp.empty()) {
                q.push(dp.front());
                dp.pop();
            }
            result++;
        }

        bool flag2 = true;
        for (int i = 0; i < n; i++) {
            if (flag[i]) {
                flag2 = false;
                break;
            }
        }

        if (flag2) {
            cout << result - 1 << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}