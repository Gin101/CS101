#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxN = 2001;
int e[maxN][maxN] = {{0}};
int dp[maxN] = {0};
bool flag[maxN] = {false};
const int INF = 0x3f3f3f3f;
int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    memset(e, INF, sizeof(e));//giganic

	for (int i = 0; i < m; i++) {
        int a = 0;
        int b = 0;
        int c = 0;
        cin >> a >> b >> c;

		e[a][b] = min(e[a][b], c);
		e[b][a] = min(e[b][a], c);
	}

    flag[1] = true;
	for (int i = 2; i <= n; i++) {
        dp[i] = e[1][i];
    }

    int idx = 0;
    int result = 0;
	for (int i = 2; i <= n; i++) {
        int tmp = INF;
		for (int j = 2; j <= n; j++) {
            if (!flag[j] && dp[j] < tmp) {
                tmp = dp[j];
                idx = j;
            }
        }

		flag[idx] = true;
        result = dp[idx];
		for (int j = 2; j <= n; j++) {
            if (!flag[j] && e[j][idx] < dp[j]) {
                dp[j] = e[j][idx];
            }
        }
	}

	cout << result << endl;

	return 0;
}