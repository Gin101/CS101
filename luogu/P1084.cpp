#include <iostream>
#include <stdio.h>

using namespace std;

const int maxN = 50001;
int f[maxN] = {0};
int _rank[maxN] = {0};

int find(int x) {
	if (f[x] == x) {
		return x;
	}
	int idx = f[x];
	f[x] = find(f[x]);
	_rank[x] = (_rank[idx] + _rank[x]) % 3;
	return f[x];
}

int main()
{
	int n = 0;
	int k = 0;
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
	
	int result = 0;
	for (int i = 0; i < k; i++) {
		int d = 0;
		int x = 0;
		int y = 0;
		scanf("%d %d %d", &d, &x, &y);
		
		if (x > n || y > n || (x == y && d == 2)) {
			result++;
			continue;
		}
		
		int fx = find(x);
		int fy = find(y);
		if (d == 1) {
			if (fx == fy && _rank[x] != _rank[y]) {
				result++;
			}
			if (fx != fy) {
				f[fx] = fy;
				_rank[fx] = (_rank[y] - _rank[x] + 3) % 3;
			}
		} else {
			if (fx == fy && (_rank[x] + 1) % 3 != _rank[y] % 3) {
				result++;
			}
			
			if (fx != fy) {
				f[fx] = fy;
				_rank[fx] = (_rank[y] - _rank[x] + 5) % 3;
			}
		}
	}
	
	cout << result << endl;
	
	return 0;
}