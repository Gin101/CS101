#include <iostream>

using namespace std;

int dfs(int m, int n) {
    if (m <= 1 || n <= 1) {
        return 1;
    }
    if (m < n) {
        return dfs(m, m);
    }
    return dfs(m, n - 1) + dfs(m - n, n);
}
int main()
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int m = 0;
        int n = 0;
        cin >> m >> n;

        cout << dfs(m, n) << endl;
    }

    return 0;
}