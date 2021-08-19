#include <iostream>
// #include <stdio.h>
#include <cstdio>
#include <stdio.h>
#include <algorithm>
#include <limits.h>
#include <cstring>

using namespace std;

const int maxN = 15;
const int maxNeed = 35;
int money[maxN] = {0};
int cache[maxNeed];

int main()
{
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);

    int n = 0;
    int need = 0;
    int minMoney = INT_MAX;
    cin >> n >> need;

    for (int i = 0; i < n; i++) {
        cin >> money[i];
        // if (minMoney > money[i]) {
        //     minMoney = money[i];
        // }
    }

    memset(cache, need + 1, sizeof(cache));

    cache[0] = 0;

    for (int i = 1; i <= need; i++) {
        // cout << "i: " << i << endl;
        for (int j = 0; j < n; j++) {
            if (i >= money[j]) {
                // if (cache[i - money[j]] == 0 && i - money[j] != 0) {
                //     continue;
                // }
                cache[i] = min(cache[i - money[j]], cache[i]) + 1;
            }
        }
        // cout << cache[i] << endl; 
    }

    if (cache[need] == need + 1) {
        cout << "-1" << endl;
    } else {
        cout << cache[need] << endl;
    }

    return 0;
}