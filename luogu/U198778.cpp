#include <iostream>

using namespace std;

int main()
{
	int t = 0;
	cin >> t;
	
	for (int i = 0; i < t; i++) {
		int n = 0;
		int m = 0;
        scanf("%d %d", &n, &m);
		
		n *= 2;
		if (n % m != 0) {
			cout << 0 << endl;
			continue;
		} else {
			n /= m;
			if ((m - 1) % 2 == 0) {
			    if (m - 1 == 0) {
                    printf("%d\n", n + 1);
			    } else {
                    printf("%d\n", n / (m - 1) + 1);
			    }
			} else {
				if (m - 1 == 0) {
                    printf("%d\n", n / 2 + 1);
				} else {
                    printf("%d\n", (n / (m - 1)) / 2 + 1);	
				}
			}
		}
	}
	
	return 0;
}