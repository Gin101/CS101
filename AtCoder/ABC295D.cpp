#include <iostream>
#include <string>

using namespace std;

int dp[1 << 10] = {0};
int main()
{
    string s;
    cin >> s;

    long long result = 0;

    dp[0]++;
    int idx = 0;
    for (int i = 0; i < s.size(); i++) {
        idx ^= 1 << (s[i] - '0');
        result += dp[idx]++;
    }

    cout << result << endl;
	
    return 0;
}