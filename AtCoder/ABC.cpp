#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxN = 2e5;
int a[maxN] = {0};

int main() 
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int q = 0;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l = 0;
        int r = 0;
        cin >> l >> r;
        int result = 0;

        for (int j = 1; j < n; j += 2) {
            int sleep_start = a[j];
            int sleep_end = a[j + 1];

            if (sleep_end <= l || sleep_start >= r) {
                continue;
            }

            result += min(r, sleep_end) - max(l, sleep_start);
        }

        cout << result << endl;
    }

    return 0;
}