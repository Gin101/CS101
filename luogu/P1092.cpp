#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int n = 0;
const int maxN = 100;
string s;
string s2;
string s3;
int num[maxN] = {0};
int cnt[maxN] = {0};
void dfs(int idx, int now) {
	if (idx == -1) {
		for (int i = 0; i < n; i++) {
            cout << num[i + 'A'] << ' ';
        }

        cout << endl;
		exit(0);
	}
	if (num[s[idx]] != -1 && num[s2[idx]] != -1 && num[s3[idx]] != -1) {
		if (((num[s[idx]] + num[s2[idx]] + now) % n) == num[s3[idx]]){
			dfs(idx - 1, (num[s[idx]] + num[s2[idx]] + now) / n);
		}
		return;
	}
	if (num[s[idx]] != -1 && num[s2[idx]] != -1) {
		if (!cnt[(num[s[idx]] + num[s2[idx]] + now) % n]){
			cnt[(num[s[idx]] + num[s2[idx]] + now) % n] = 1;
			num[s3[idx]] = (num[s[idx]] + num[s2[idx]] + now) % n;
			dfs(idx - 1, (num[s[idx]] + num[s2[idx]] + now) / n);
			num[s3[idx]] = -1;
			cnt[(num[s[idx]] + num[s2[idx]] + now) % n] = 0;
		}
		return;
	}
	if (num[s[idx]] != -1 && num[s3[idx]] != -1) {
		if (!cnt[(num[s3[idx]] - now - num[s[idx]] + n) % n]) {
			cnt[(num[s3[idx]] - now - num[s[idx]] + n) % n] = 1;
			num[s2[idx]] = (num[s3[idx]] - now - num[s[idx]] + n) % n;
			dfs(idx - 1, !((num[s3[idx]] - now - num[s[idx]] + n) / n));
			num[s2[idx]] = -1;
			cnt[(num[s3[idx]] - now - num[s[idx]] + n) % n] = 0;
		}
		return;
	}
	if (num[s2[idx]] != -1 && num[s3[idx]] != -1) {
		if(!cnt[(num[s3[idx]] - now - num[s2[idx]] + n) % n]){
			cnt[(num[s3[idx]] - now - num[s2[idx]] + n) % n] = 1;
			num[s[idx]] = (num[s3[idx]] - now - num[s2[idx]] + n) % n;
			dfs(idx - 1, !((num[s3[idx]] - now - num[s2[idx]] + n) / n));
			num[s[idx]] = -1;
			cnt[(num[s3[idx]] - now - num[s2[idx]] + n) % n] = 0;
		}
		return;
	}

	if (num[s[idx]] != -1) {
		for (int i = n - 1; i >= 0; i--) {
            if (!cnt[i]) {
                cnt[i] = 1;
                num[s2[idx]] = i;
                dfs(idx, now);
                num[s2[idx]] = -1;
                cnt[i] = 0;
            }
        }
	} else {
        for (int i = n - 1; i >= 0; i--) {
            if (!cnt[i]) {
                cnt[i] = 1;
                num[s[idx]] = i;
                dfs(idx, now);
                num[s[idx]] = -1;
                cnt[i] = 0;
            }
        }
	}
}
int main()
{
    cin >> n >> s >> s2 >> s3;

	memset(num, -1, sizeof num);
	dfs(n - 1, 0);

	return 0;
}