#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int n = 0;
const int maxN = 1000;
int a[maxN] = {0};
int ope(int num, int cnt) {
    if (num == 1) {
        return cnt;
    } else if (num % 2 == 0) {
        return ope(num / 2, cnt + 1);
    } else if (num % 3 == 0) {
        return ope(num / 3, cnt + 1);
    } else {
        return -1;
    }
}

int init(int num) {
    if (num % 2 == 0) {
        return init(num / 2);
    } else if (num % 3 == 0) {
        return init(num / 3);
    } else {
        return num;
    }
}


bool check(int num) {
    for (int i = 0; i < n; i++) {
        if (a[i] % num != 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> n;

    int total = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total = min(total, a[i]);
    }

    total = init(total);
    while (check(total * 2)) {
        total *= 2;
    }
    while (check(total * 3)) {
        total *= 3;
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % total != 0) {
            cout << -1 << endl;
            return 0;
        }
        int tmp = ope(a[i] / total, 0);
        if (tmp == -1) {
            cout << -1 << endl;
            return 0;
        }
        result += tmp;
    }

    cout << result << endl;

    return 0;
}