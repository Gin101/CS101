#include <iostream>

using namespace std;

const int maxN = 501;
const int maxS = 45001;
int s[maxN] = {0};
int dp[maxN][maxS] = {{0}};

int main()
{
    int h = 0;
    int n = 0;
    cin >> h >> n;

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }



    return 0;
}