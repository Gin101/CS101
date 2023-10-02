#include <iostream>
#include <algorithm>

using namespace std;

int n = 0;
int result = 0;
const int maxN = 8;
int a[maxN * 2][maxN * 2] = {{0}};
void dfs(int num, int now) {
    int idx = 0;
    while (idx < 2 * n && num >> idx & 1) {
        idx++;
    }
    if (idx == 2 * n) {
        result = max(result, now);
        return;
    }

    num |= 1 << idx;
    for (int i = idx + 1; i < 2 * n; i++) {
        if (!(num >> i & 1)) {
            dfs(num | 1 << i, now ^ a[idx][i]);
        }
    }
}
int main()
{
    cin >> n;

    for (int i = 0; i < 2 * n; i++) {
        for (int j = i + 1; j < 2 * n; j++) {
            cin >> a[i][j];
        }
    }
	
    dfs(0, 0);

    cout << result << endl;

    return 0;
}