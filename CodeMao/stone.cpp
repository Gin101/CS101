#include <iostream>

using namespace std;

const int maxN = 50000;
int s[maxN] = {0};

int main()
{
	int l = 0;
	int n = 0;
	int m = 0;
	int mid = 0;
	int result = 0;
	
	cin >> l >> n >> m;
	
	for(int i = 1; i <= n;i++) {
		cin >> s[i];
	}
	
	int left = 0;
	int right = l;
	
	while (left <= right) {
		mid = (right + left) / 2;
		int now = 0;
		int tmp = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] - s[now] < mid) {
				tmp++;
			} else {
				now = i;
			}
		}
		
		if (tmp <= m) {
			result = mid;
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}	
	
	cout << result << endl;

	return 0;
}