#include <iostream>

using namespace std;

const int maxN = 2000;
int dp[maxN] = {0};

int main()
{
    int n = 0;
    while (cin >> n) {
        int result = 0;
        for (int i = 0; i < n; i++) {
            int num = 0;
            cin >> num;

            if (i == 0 || num < dp[result - 1]) {
                dp[result++] = num;
            } else {
                for (int j = 0; j < result; j++) {
                    if (num > dp[j]) {
                        dp[j] = num;
                        break;
                    }
                }	
            }
        }
        
        if (result == 2) {
            cout << "Yes!" << endl;
        } else {
            cout << "No!" << endl;
        }
    }
	
	return 0;
}