#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

const int maxS = 1e4 + 1;
bool flag = false;
int num[maxS] = {0};
int result[maxS] = {0};
int idx = 1;

void dfs(int x, int y, int a, int b) {
    int tmp = __gcd(a, b);
    a /= tmp;
    b /= tmp;

    if (x == idx) {
        if (a == 1 && b > y) {
            num[idx] = b;
            flag = true;

            if (num[idx] < result[idx] || !result[idx]) {
                for (int i = 1; i <= idx; i++) {
                    result[i] = num[i];
                }
            }
        }
        return;
    }

    for (int i = max(y + 1, b / a); b * (idx - x + 1) >= a * i; i++) {
        if (a * i >= b) {
            num[x] = i;
            dfs(x + 1, i, a * i - b, b * i);
        }
    }
}

signed main() 
{
    int a = 0;
    int b = 0;
    cin >> a >> b;

    while (!flag) {
        dfs(1, 1, a, b);
        idx++;
    }

    for (int i = 1; i < idx; i++) {
        cout << result[i] << ' ';
    }
    cout << endl;

    return 0;
}