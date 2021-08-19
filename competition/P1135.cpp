#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int maxN = 200;
int l[maxN] = {0};//lift
int result[maxN] = {0};

int main()
{
	int n = 0;
	int a = 0;
	int b = 0;
	cin >> n >> a >> b;
	
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}
	
	queue<int> q;
	q.push(a);
	memset(result, -1, sizeof(result));
	result[a - 1] = 0;
	
	while (!q.empty()) {
		if (q.front() == b) {
			cout << result[b - 1] << endl;
			return 0;
		}
		
		int tmp = q.front();//use tmp to instead the front of the queue
		int sum = tmp + l[tmp - 1];
		if (sum <= n && result[sum - 1] == -1) {
			q.push(sum);
			result[sum - 1] = result[tmp - 1] + 1; 
		}
		int minus = tmp - l[tmp - 1];
		if (minus >= 0 && result[minus - 1] == -1) {
			q.push(minus);
			result[minus - 1] = result[tmp - 1] + 1;
		}

		q.pop();
 	}
 	
 	cout << -1 << endl;
	
	return 0;
}