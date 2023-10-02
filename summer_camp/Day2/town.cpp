#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>

#define int long long

using namespace std;

const int maxN = 5e6;
int a[maxN] = {0};
int b[maxN] = {0};
int result[maxN] = {0};
queue<int> q;

signed main()
{
    freopen("town.in", "r", stdin);
    freopen("town.out", "w", stdout);

    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    q.push(n - 1);
    for (int i = n - 2; i >= 0; i--) {
        int idx = q.front();
        while (!q.empty() && a[i] < a[q.front()]) {
            result[idx] += b[q.front()];
            q.pop();
        }

        q.push(i);
    }

    int idx = q.front();
    while (!q.empty()) {
        result[idx] += b[q.front()];
        q.pop();
    }

    q.push(0);
    for (int i = 1; i < n; i++) {
        int idx = q.front();

        bool flag = false;
        while (!q.empty() && a[i] < a[q.front()]) {
            result[idx] += b[q.front()];
            q.pop();
            flag = true;
        }

        q.push(i); 

        if (flag) {
            result[idx] -= b[idx];
        }
    }

    idx = q.front();
    while (!q.empty()) {
        result[idx] += b[q.front()];
        q.pop();
    }
    result[idx] -= b[idx];


    int total = 0;
    for (int i = 0; i < n; i++) {
        total = max(total, min(a[i], result[i]));
    }

    cout << total * total << endl;
    
    return 0;                                                                    
}