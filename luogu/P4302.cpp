#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

string s;
const int maxN = 101;
const int INF = 0x3f3f3f3f;
int dp[maxN][maxN] = {{0}};
int digit[maxN] = {0};
bool check(int l, int r, int len) {
	for (int i = l; i <= r; i++) {
		if (s[i - 1] != s[(i - l) % len + l - 1]) {
			return false;
		}
	}

	return true;
}
int main()
{
	cin >> s;

	for (int i = 1; i <= 9; i++) {
		digit[i] = 1;
	}
	for (int i = 10; i <= 99; i++) {
		digit[i] = 2;
	}
	digit[100] = 3;

	memset(dp, INF, sizeof(dp));
	for (int i = 1; i <= s.size(); i++) {
		dp[i][i] = 1;
	}
	for (int i = 2; i <= s.size(); i++) {
		for (int j = 1, idx = i + j - 1; idx <= s.size(); j++, idx++) {
			for (int k = j; k < idx; k++) {
				dp[j][idx] = min(dp[j][idx], dp[j][k] + dp[k + 1][idx]);
			}
			for (int k = j; k < idx; k++) {
				if (i % (k - j + 1)) {
					continue;
				}	
				if (check(j, idx, k - j + 1)) {
					dp[j][idx] = min(dp[j][idx], dp[j][k] + 2 + digit[i / (k - j + 1)]);
				}
			}
		}
	}
	
	cout << dp[1][s.size()] << endl;

    return 0;
}
