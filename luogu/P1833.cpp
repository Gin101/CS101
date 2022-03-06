#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 1e4 + 1;
const int maxTD = 1001;
int t[maxN] = {0};
int c[maxN] = {0};
int p[maxN] = {0};
int dp[maxTD] = {0};
bool flag[maxN] = {false};

int main() 
{
    int ts = 0;
    int te = 0;
    for (int i = 0; i < 2; i++) {
        int hh = 0;
        char c;
        int mm = 0;
        cin >> hh >> c >> mm;

        if (i == 0) {
            ts = hh * 60 + mm;
        } else {
            te = hh * 60 + mm;
        }
    }

    int td = 0;// time different
	if (te >= ts) {
        td = te - ts;
    } else {
        td = 1440 - ts + te;
    }

    int n = 0;
    cin >> n;

    int idx = n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> c[i] >> p[i];

		if (p[i] <= 1) {
            continue;
        }
		flag[i] = 1;
        int idx2 = 1;
        while ((idx2 << 1) - 1 <= p[i]) {
			t[++idx] = t[i] * idx2;
            c[idx] = c[i] * idx2;
            p[idx] = 1;
            idx2 <<= 1;
		}

		if (p[i] == idx2 - 1) {
            continue;
        }
		t[++idx] = t[i] * (p[i] - idx2 + 1);
		c[idx] = c[i] * (p[i] - idx2 + 1);
		p[idx] = 1;
	}
	
	for (int i = 1; i <= idx; i++) {
		if (flag[i]) {
            continue;
        }
		if (p[i] == 1) {
            for (int j = td; j >= t[i]; j--) {
                dp[j] = max(dp[j], dp[j - t[i]] + c[i]);
            }
        } else {
            for (int j = t[i]; j <= td; j++) {
                dp[j] = max(dp[j], dp[j - t[i]] + c[i]);
            }
        }
	}
	
	cout << dp[td] << endl;
	
	return 0;
}