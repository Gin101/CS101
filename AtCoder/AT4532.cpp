#include <iostream>

using namespace std;

const int maxN = 101;
const int maxK = 1e5 + 1;
int a[maxN] = {0};
int dp[maxK] = {0};

int main() 
{
    int n = 0;
    int k = 0;
    cin >> n >> k;

	for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
	
	dp[0] = 0;
	for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            if (i - a[j] >= 0) {
                dp[i] |= !dp[i - a[j]];
            }
        }
    }		
	
	if (dp[k]) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
	
	return 0;
}