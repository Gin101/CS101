#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int maxN = 1e6;
struct Job {
	int d = 0;
	int p = 0;
} work[maxN];

bool cmp(Job x, Job y) {
	return x.d < y.d;
}


int main() 
{
	int n = 0;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> work[i].d >> work[i].p;
	}
		
	sort(work, work + n, cmp);
	
	priority_queue<int, vector<int>, greater<int> > q;
	for (int i = 0; i < n; i++) {
		q.push(work[i].p);
		if (q.size() > work[i].d) {
			q.pop();
		}
	}
	
	long long result = 0;
	while (!q.empty()){
		result += (q.top());
		q.pop();
	}
	
	cout << result << endl;
	
    return 0;
}