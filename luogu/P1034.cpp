#include <iostream>

using namespace std;

int n = 0;
const int maxN = 50;
int x[maxN] = {0};
int y[maxN] = {0};
bool flag[maxN] = {false};
int num[maxN] = {0};
void ope(int )

void dfs(int need, int idx) {
    if (need == 0) {

    }

    for (int i = 0; i < n; i++) {
        if (!flag[i]) {
            num[idx++] = i;
            flag[i] = true;
            dfs(need - 1, idx);
            flag[i] = false;
            idx--;
        }
    }
}

int main()
{
    int k = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    dfs(k, 0);

    return 0;
}