#include <iostream>

using namespace std;

const int maxN = 10000;

int main()
{
//	freopen("war.in", "r", stdin);
//	freopen("war.out", "w", stdout);
	
	int n = 0;
	int m = 0;
	cin >> n >> m;

	int winA[maxN] = {0};
	int winB[maxN] = {0};
	int winC[maxN] = {0};
	
	for (int i = 0; i < n; i++) {
		long long peopleA = 0;
		long long peopleB = 0;
		long long peopleC = 0;
		cin >> peopleA >> peopleB >> peopleC;

		if (peopleA > peopleB && peopleA > peopleC) {
			winA[i] = 1;
		} else if (peopleB > peopleA && peopleB > peopleC) {
			winB[i] = 1;
		} else if (peopleC > peopleA && peopleC > peopleB) {
			winC[i] = 1;
		}
	}
	
	for (int i = 0; i < m; i++) {
		int start = 0;
		int end = 0;
		cin >> start >> end;
		
		int tmpA = 0;
		int tmpB = 0;
		int tmpC = 0;
		
//		int bound = (end - start) / 2;
		for (int j = start - 1; j < end; j++) {
			tmpA += winA[j];
			tmpB += winB[j];
			tmpC += winC[j];
		}
		
		if (tmpA > tmpB && tmpA > tmpC) {
			cout << 'A' << endl;
		} else if (tmpB > tmpA && tmpB > tmpC) {
			cout << 'B' << endl;
		} else if (tmpC > tmpA && tmpC > tmpB) {
			cout << 'C' << endl;
		} else {
			cout << 'D' << endl;
		}
	}

	return 0;
} 
