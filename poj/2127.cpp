#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

const int maxN = 501;
const int maxM = 501;
int a[maxN] = {0};
int b[maxM] = {0};
int dp[maxN][maxM] = {{0}};
pair<int, pair<int, bool> > idx[maxN][maxM];
stack<int> st;

int main() 
{
	int n = 0;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
    int m = 0;
    cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i] == b[j]) {
                for (int k = 0; k < j; k++) {
                    if (b[k] <= a[i]) {
                        idx[i][j].first = dp[i][j] < dp[i - 1][k] + 1 ? i - 1 : idx[i][j].first;
                        idx[i][j].second.first = dp[i][j] < dp[i - 1][k] + 1 ? k : idx[i][j].second.first;
                        idx[i][j].second.second = dp[i][j] < dp[i - 1][k] + 1 ? true: idx[i][j].second.second;
                        // cout << i << ' ' << j << ' ' << k << ' ' << idx[i][j].first << ' ' << idx[i][j].second.first << endl;
                        dp[i][j] = max(dp[i][j], dp[i - 1][k] + 1);
                    }
                }
			} else {
                idx[i][j].first = i - 1;
                idx[i][j].second.first = j;
                idx[i][j].second.second = false;
                dp[i][j] = dp[i - 1][j];
                // cout << i << ' ' << j << ' ' << idx[i][j].first << ' ' << idx[i][j].second.first << endl;
			}
		}
	} 

    int result = 0;
    int resultIdx = 0;
    int resultIdx2 = 0;
    for (int i = 1; i <= m; i++) {
        if (dp[n][i] > result) {
            result = dp[n][i];
            resultIdx = n;
            resultIdx2 = i;
        }
    }

    cout << result << endl;
    st.push(b[resultIdx2]);
    while (idx[resultIdx][resultIdx2].first && idx[resultIdx][resultIdx2].second.first) {
        if (idx[resultIdx][resultIdx2].second.second) {
            st.push(b[idx[resultIdx][resultIdx2].second.first]);
        }

        int tmp = resultIdx;
        resultIdx = idx[resultIdx][resultIdx2].first;
        resultIdx2 = idx[tmp][resultIdx2].second.first;
    }

    while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }

    cout << endl;
	
    return 0;
}