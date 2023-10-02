#include <iostream>

using namespace std;

int n = 0;
const int maxN = 5e5 + 1;
int t[maxN] = {0};
int lowbit(int x) {
    return x & -x;
}
int getSum(int x) {
    int result = 0;
    while (x > 0) {
        result += t[x];
        x -= lowbit(x);
    }
    return result;
}
void add(int x, int k) {
    while (x <= n) {
        t[x] += k;
        x += lowbit(x);
    }
}

int main()
{
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int num = 0;
        cin >> num;

        add(i + 1, num);
    }

    for (int i = 0; i < m; i++) {
        int op = 0;
        cin >> op;

        int x = 0;
        int y = 0;
        if (op == 1) {
            cin >> x >> y;

            add(x, y);
        } else {
            cin >> x >> y;

            cout << getSum(y) - getSum(x - 1) << endl;
        }
    }

    return 0;
}