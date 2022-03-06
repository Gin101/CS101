#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int maxN = 3001;
const int MOD = 1e9 + 7;

long long dp[maxN][maxN] = {{0}};
long long num[maxN] = {0};
int main() 
{
    int n = 0;
    string s;
	cin >> n >> s;
	
	dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		memset(num, 0, sizeof num);
		for (int j = 1; j <= i; j++) {
            num[j] = (num[j - 1] + dp[i - 1][j]) % MOD;
        }
		
		for (int j = 1; j <= i; j++) {
			if (s[i - 2] == '>') {
				if (num[i - 1] < num[j - 1]) num[i - 1] += MOD;
				dp[i][j] = (num[i - 1] - num[j - 1]) % MOD;
			} else {
				dp[i][j] = (num[j - 1] - num[0]) % MOD;
			}
		}
	}
	
	long long result = 0;
	for (int i = 1; i <= n; i++) {
        result = (result + dp[n][i]) % MOD;
    }
	
	cout << result << endl;
	
	return 0;
}