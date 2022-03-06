#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 201;
const int MOD = 504;
int g[maxN] = {0};
int dp[maxN][maxN] = {{0}};
int main()
{
    int n = 0;
    int k = 0;
    cin >> n >> k;

    int result = 1;
    for (int i = 0; i < k; i++) {
        result *= (n - i);
    }

    cout << result << endl;
    
	return 0;
}
