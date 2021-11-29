#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int maxN = 2e5 + 1;
int sum[maxN] = {0};
int ma[maxN] = {0};//max of sum
int mi[maxN] = {0};//min of sum
int _ma[maxN] = {0};//max of ma
int _mi[maxN] = {0};//min of mi
int main()
{
	int t = 0;
    cin >> t;
	
    for (int i = 0; i < t; i++) {
        int n = 0;
        int m = 0;
        string s;
        cin >> n >> m >> s;

		for (int i = 1; i <= n; i++) {
			if (s[i - 1] == '-') {
                sum[i] = sum[i - 1] - 1;
            } else {
                sum[i] = sum[i - 1] + 1;
            }
			mi[i] = min(mi[i - 1], sum[i]);
			ma[i] = max(ma[i - 1], sum[i]);
		}

		_mi[n + 1] = 0;
        _ma[n + 1] = 0;
		for (int i = n; i >= 1; i--) {
			if (s[i - 1] == '-') {
				_mi[i] = min(-1, _mi[i + 1] - 1);
				_ma[i] = max(-1, _ma[i + 1] - 1);
			} else {
				_mi[i] = min(1, _mi[i + 1] + 1);
				_ma[i] = max(1, _ma[i + 1] + 1);
			}
		}

		for (int i = 1; i <= m; i++) {
            int l = 0;
            int r = 0;
            cin >> l >> r;

			cout << max(sum[l - 1] + _ma[r + 1], ma[l - 1]) - min(sum[l - 1] + _mi[r + 1], mi[l - 1]) + 1 << endl;
		} 
	}
	return 0;
}
