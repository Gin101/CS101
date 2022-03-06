#include <iostream>

using namespace std;


void dfs(int sum, int need) {
    if (sum == 0) {
        if (need == 0) {

        }
    }

    for (int i = 1; i <= sum; i++) {
        dfs(sum - i, need + 1);
    }
}

int main()
{
    int n = 0;
    int k = 0;
    cin >> n >> k;

    dfs(n, k);

    return 0;
}