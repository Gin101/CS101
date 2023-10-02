#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

string s;
long long n = 0;
long long result = -1;

long long np(long long x, long long y) {
    long long res = 1;
    for (int i = 0; i < y; i++) {
        res *= x;
    }
    return res;
}
void ope(int idx, long long tmp) {
    if (tmp > n) {
        return;
    }
    if (idx == s.size()) {
        result = max(result, tmp);
        return;
    }
    if (s[idx] == '1') {
        ope(idx + 1, tmp + np(2, s.size() - idx - 1ll));
    } else if (s[idx] == '?') {
        if (tmp + np(2, s.size() - idx) - 1ll <= n) {
            ope(idx + 1, tmp + np(2, s.size() - idx - 1ll));
        } else if (tmp + np(2, s.size() - idx - 1ll) > n) {
            ope(idx + 1, tmp);
        } else {
            ope(idx + 1, tmp + np(2, s.size() - idx - 1ll));
            ope(idx + 1, tmp);
        }
    } else {
        ope(idx + 1, tmp);
    }
}

int main()
{
    cin >> s >> n;
    ope(0, 0);

    cout << result << endl;

    return 0;
}