#include <iostream>
#include <algorithm>

using namespace std;

const int maxLen = 26;
int dp[maxLen][maxLen] = {{0}};
int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < 26; j++) {
            if (dp[j][s[0] - 'a'] != 0) {
                dp[j][s[s.size() - 1] - 'a'] = max(dp[j][s[s.size() - 1] - 'a'], dp[j][s[0] - 'a'] + (int)s.size());
            }
        }

        dp[s[0] - 'a'][s[s.size() - 1] - 'a'] = max(dp[s[0] - 'a'][s[s.size() - 1] - 'a'], (int)s.size());
    }

	int result = 0;
    for (int i = 0; i < 26; i++) {
        result = max(result, dp[i][i]);
    }
	
    cout << result << endl;

    return 0;
}