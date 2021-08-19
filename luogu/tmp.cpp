#include <iostream>

using namespace std;

int n = 0;
int m = 0;
const int maxM = 10;
int num[maxM] = {0};
int result[maxM] = {0};

void dfs(int sum, int cnt, int idx) {
    if (sum > n) {
        return;
    } else if (sum == n) {
        for (int i = 0; i < cnt; i++) {
            cout << result[i] << ' ';
        }
        
        cout << endl;
        return;
    }

    for (int i = idx; i < m; i++) {
        result[cnt] = num[i];
        dfs(sum + num[i], cnt + 1, i + 1);
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> num[i];
    }

    dfs(0, 0, 0);

    return 0;
}
