#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 2e5;
const int maxA = 2e5;
int a[maxN] = {0};
int cnt[maxA] = {0};

int main()
{
    int n = 0;
    cin >> n;

    int maxa = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i] - 1]++;
        maxa = max(maxa, a[i]);
    }

    sort(a, a + n);

    int result = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] * a[i] > maxa) {
            break;
        }
        for (int j = i; j < n; j++) {
            if (a[i] * a[j] > maxa) {
                break;
            }
            if (cnt[a[i] * a[j] - 1]) {
                if (i == j) {
                    result += cnt[a[i] * a[j] - 1];
                } else {
                    result += 2 * cnt[a[i] * a[j] - 1];;
                }
            }
        }
    }

    cout << result << endl;

    return 0;
}