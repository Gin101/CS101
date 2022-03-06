#include <iostream>
#include <queue>

using namespace std;

const int maxN = 2e6 + 1;
const int maxM = 2e6 + 1;
int a[maxN] = {0};
int result[maxM] = {0};

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int l = 1;
    int r = 0;
    for (int i = 1; i <= n; i++) {
        cout << a[result[l]] << endl;
        if (i - result[l] + 1 > m && l <= r) {
            l++;
        }

        while (a[i] < a[result[r]] && l <= r) {
            r--;
        }
        result[++r] = i;
    }	

    return 0;
}