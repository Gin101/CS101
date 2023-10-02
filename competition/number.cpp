#include <iostream>

using namespace std;

const int maxK = 200;
bool flag[maxK] = {false};
int main()
{
    int x = 0;
    int y = 0;
    int k = 0;
    cin >> x >> y >> k;

    int cnt = 0;
    int idx = -1;
    while (cnt < y) {
        int cnt2 = 0;
        while (cnt2 < k) {
            idx++;
            idx %= (x + y);
            if (!flag[idx]) {
                cnt2++;
            }
        }
        flag[idx] = true;
        cnt++;
    }

    for (int i = 0; i < x + y; i++) {
        if (!flag[i]) {
            cout << i + 1 << ' ';
        }
    }

    cout << endl;

    return 0;
}