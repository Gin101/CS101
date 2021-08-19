#include <iostream>

using namespace std;

const int maxN = 100;
int p[maxN] = {0};
int n = 0;
int result = 0;

void dfs(int start, int end)
{
	if (start >= n) {
		return;
	}
	
	int sum = 0;
	for (int i = start; i <= end; i++) {
		sum += p[i];
	}
	
	int count = end - start + 1;
	if (sum % count == 0) {
		int average = sum / count;
		for (int i = start; i <= end; i++) {
			if (average == p[i]) {
				result++;
				break;
			}
		}
	}
	
	if (end + 1 < n) {
		dfs(start, end + 1);
	} else {
		dfs(start + 1, start + 1);
	}
}

int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	
	dfs(0, 0);
		
	cout << result << endl;
		
	return 0;
}
