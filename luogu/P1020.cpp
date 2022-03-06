#include <iostream>
#include <algorithm>
using namespace std;

const int maxN = 100000;
int dp[maxN] = {0};
int dp2[maxN] = {0};

int main()
{
    int num = 0;
	int idx = 0;
	int result = 0;
    int result2 = 0;
	while (cin >> num) {
		if (idx == 0 || num <= dp[result - 1]) {
			dp[result++] = num;
		} else {
			for (int j = 0; j < result; j++) {
				if (num > dp[j]) {
					dp[j] = num;
					break;
				}
			}	
		}

        if (idx == 0 || num > dp2[result2 - 1]) {
			dp2[result2++] = num;
		} else {
			for (int j = 0; j < result2; j++) {
				if (num <= dp2[j]) {
					dp2[j] = num;
					break;
				}
			}	
		}

        idx++;
	}
	
	cout << result << endl << result2 << endl;
	
	return 0;
}