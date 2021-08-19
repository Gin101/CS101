#include <iostream>
#include <limits.h>
#include <stdio.h>

using namespace std;

const int maxK = 65;
bool flag[65] = {false};
bool flag2[65] = {false};
int main() 
{
    int n = 0;
    int m = 0;
    int c = 0;
    int k = 0;
    cin >> n >> m >> c >> k;

    for (int i = 1; i <= n; i++) {
        unsigned long long a = 0;
        // cin >> a;
        scanf("%lld", &a);

        for (int j = k - 1; j >= 0; j--) {
            flag[j] |= (a >> j) & 1;
        }
    }

    for (int i = 1; i <= m; i++) {
        int p = 0;
        int q = 0;
        cin >> p >> q;

        if (!flag[p]) {
            flag2[p] = true;
        }
    }

    int cnt = 0;
    for (int i = 0; i < k; i++) {
        if (flag2[i]) {
            cnt++;
        }
    }

    if (k - cnt == 64) {
        if (n) {
            cout << (unsigned long long)(-n) << endl;
        } else {
            cout << ULONG_MAX << endl;
        }
    } else {
        cout << (1ull << (k - cnt)) - n << endl;    
    }
        
    return 0;
}