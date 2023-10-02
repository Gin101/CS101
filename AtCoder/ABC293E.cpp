#include <iostream>

using namespace std;

int main() 
{
	int a = 0;
	long long x = 0;
	int m = 0;
	cin >> a >> x >> m;

	int tmp = 1;
	int result = 0;
	while (x) {
		if (x & 1) {
			result = (1ll * result * a + tmp) % m;
		}
		tmp = 1ll * tmp * (a + 1) % m;
		a = 1ll * a * a % m;
		x /= 2;
	}
	
	cout << result << endl;

	return 0;
}