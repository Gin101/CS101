#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
//	freopen("fruit.in", "r", stdin);
//	freopen("fruit.out", "w", stdout);
	
	int n = 0;
	cin >> n;
	
	int k = 0;
	int x = 0;
	double y = 0;
	int z = 0;
	double result = 0;
	
	for (int i = 0; i < n; i++) {
		cin >> k >> x >> y >> z;
		if (k == 1) {
			if (y == 0) {
				cout << "Failed" << endl;
				continue;
			}
			
			int need = ceil(x / y);
			if (need > z) {
				cout << "Failed" << endl;
			} else {
				cout << need << endl;
				result += x;
			}
		} else {
			if (x > z) {
				cout << "Failed" << endl;
			} else {
				printf("%.3lf\n", x * y);
				result += x * y;
			}
		}
	}
	
//	printf("%.3lf", result);
	cout << fixed << setprecision(3) << result << endl;
	
	return 0;
}
