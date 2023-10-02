#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int maxN = 5e5 + 1;
int s[maxN] = {0};
int d[maxN] = {0};
int main() 
{
    int n = 0;
    string tmp;
    cin >> n >> tmp;

    for (int i = 0; i < n; i++) {
        if (tmp[i] == '1') {
            s[i] = 1;
        }
    }
    for (int i = 0, l = 0, r = -1; i <= n; i++) {
        int k = i > r ? 0 : min(d[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] != s[i + k]) {
            k++;
        }

        d[i] = k--;

        if (i + k > r) {
            l = i - k - 1;
            r = i + k;
        }
    }

    long long result = 0;
    for (int i = 0; i < n; i++) {
        result += 1ll * d[i];
    }

    cout << result << endl;

    return 0;
}