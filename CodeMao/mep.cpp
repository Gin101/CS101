#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 1e4;
char have[maxN] = {0};
char need[maxN] = {0};
char tmp[maxN] = {0};

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> have[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> need[i];
    }

    int m = 0;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int l = 0;
        int r = 0;
        int c = 0;
        cin >> l >> r >> c;

        c %= (r - l + 1);
        int idx = 0;
        for (int j = r - c; j < r; j++) {
            tmp[idx++] = have[j];
        }

        for (int j = r - 1; j >= l + c - 1; j--) {
            have[j] = have[j - c];
        }

        idx = 0;
        for (int j = l - 1; j < l + c - 1; j++) {
            have[j] = tmp[idx++];
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        if (have[i] == need[i]) {
            result++;
        }
    }

    cout << result << endl;

    return 0;
}