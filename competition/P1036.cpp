#include <iostream>

using namespace std;

const int maxN = 20;
int x[maxN] = {0};
bool flag[maxN] = {false};
int result = 0;
int n = 0;
void dfs(int sum, int need) {
    if (need == 0) {
        bool flag2 = true;
        for (int i = 2; i * i <= sum; i++) {
            if (sum % i == 0) {
                flag2 = false;
                break;
            }
        }

        if (flag2) {
            result++;
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!flag[i]) {
            flag[i] = true;
            dfs(sum + x[i], need - 1);
            flag[i] = false;
        }
    }
}

int main()
{
    int k = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    dfs(0, k);

    int tmp = 1;
    for (int i = 2; i <= k; i++) {
        tmp *= i;
    }

    cout << result / tmp << endl;

    return 0;
}