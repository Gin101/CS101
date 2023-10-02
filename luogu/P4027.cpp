#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

const int maxN = 1e5 + 1;
double a[maxN] = {0};
double b[maxN] = {0};
double rate[maxN] = {0};
double num[maxN] = {0};
double tmp[maxN] = {0};
double cnt[maxN] = {0};
double cnt2[maxN] = {0};
int idx = 0;
int idx2[maxN * 4] = {0};
void upd(int num2, int num3, int l, int r) {
	if (l == r) {
        if (cnt2[num3] + cnt[num3] * num[l] > cnt2[idx2[num2]] + cnt[idx2[num2]] * num[l]) {
            idx2[num2] = num3;
        }
        return;
    }

	int mid = (l + r) / 2;
    if (cnt2[num3] + cnt[num3] * num[mid] > cnt2[idx2[num2]] + cnt[idx2[num2]] * num[mid]) {
        swap(num3, idx2[num2]);
    }

    if (cnt2[num3] + cnt[num3] * num[l] > cnt2[idx2[num2]] + cnt[idx2[num2]] * num[l]) {
        upd(num2 * 2, num3, l, mid);
    } else {
        upd(num2 * 2 + 1, num3, mid + 1, r);
    }
}
double ope(int num2, int l, int r) {
	if (l == r) {
        return cnt2[idx2[num2]] + cnt[idx2[num2]] * num[idx];
    }
	int mid = (l + r) / 2;
    return max(cnt2[idx2[num2]] + cnt[idx2[num2]] * num[idx], idx > mid ? ope(num2 * 2 + 1, mid + 1, r) : ope(num2 * 2, l, mid));
}
int main()
{
    int n = 0;
    double s = 0;
    cin >> n >> s;

    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> rate[i];
        num[i] = a[i] / b[i];
        tmp[i] = num[i];
    }

	sort(num + 1, num + n + 1);
    for (int i = 1; i <= n; i++) {
        idx = lower_bound(num + 1, num + n + 1, tmp[i]) - num;
        s = max(s, b[i] * ope(1, 1, n));
        cnt[i] = s * rate[i] / (a[i] * rate[i] + b[i]);
        cnt2[i] = s / (a[i] * rate[i] + b[i]);
        upd(1, i, 1, n);
    }

	printf("%.3lf\n", s);

	return 0;
}