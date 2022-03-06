#include <iostream>
#include <limits.h>

using namespace std;

int prime[10] = {2,3,5,7,11,13,17,19,23,29};
long long result = LONG_MAX;
int n = 0;
void dfs(int idx, long long tmp, int num) {
	if (num > n) {
        return;
    }

	if (num == n && result > tmp) {
        result = tmp;
    }

    for (int i = 1; i <= 60; i++) {
        if (result / prime[idx] < tmp) {
            break;
        }

        dfs(idx + 1, tmp *= prime[idx], num * (i + 1));
    }
}
int main()
{
    cin >> n;
	dfs(0, 1, 1);

    cout << result << endl;

	return 0;
}