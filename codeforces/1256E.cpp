#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 200001;
struct Student {
    int idx = 0;
    int val = 0;
} a[maxN];
int dp[maxN] = {0};
int num[maxN] = {0};
int result2[maxN] = {0};

bool cmp(Student x, Student y) {
    return x.val < y.val;
}

const int INF = 0x3f3f3f3f;
int main()
{
    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].val;
        a[i].idx = i;
    }

    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        dp[i] = INF;
        for (int j = max(0, i - 5); j <= i - 3; j++) {
            if (dp[j] + a[i].val - a[j + 1].val < dp[i]) {
                dp[i] = dp[j] + a[i].val - a[j + 1].val;
                num[i] = j;
            }
        }
	}

	int tmp = n;
    int result = 0;
	while (tmp != 0) {
		result++;
		for (int i = num[tmp] + 1; i <= tmp; i++) {
            result2[a[i].idx] = result;
        }
		tmp = num[tmp];
	}

    cout << dp[n] << ' ' << result << endl;

    for (int i = 1; i <= n; i++) {
        cout << result2[i] << ' ';
    }
    cout << endl;

    return 0;
}