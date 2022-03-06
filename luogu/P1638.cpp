#include <iostream>

using namespace std;

const int maxN = 1e6;
const int maxM = 2000;
int num[maxM] = {0};
int a[maxN] = {0};
int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int idx = 0;
    int cnt = 0;
    int l = 0;
    int r = -1;
    while (idx != m) {
        if (num[a[cnt]] == 0) {
            idx++;
        }
        num[a[cnt]]++;
        r++;
        cnt++;
    }

    while (num[a[l]] > 1) {
        num[a[l++]]--;
    } 

    int result = l;
    int result2 = r;
    while (cnt < n) {
        num[a[cnt]]++;
        r++;
        cnt++;
        while (num[a[l]] > 1) {
            num[a[l++]]--;
        } 

        if (result2 - result > r - l) {
            result2 = r;
            result = l;
        }
    }

    cout << result + 1 << ' ' << result2 + 1 << endl;

    return 0;
}