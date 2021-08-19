#include <iostream>
#include <string>

using namespace std;

const int maxN = 5000;
unsigned long long num[maxN] = {0}; 

int main()
{
	int n = 0;
	cin >> n;
	
	if (n == 0) {
		cout << 0 << endl;
		return 0;
	}
	
	num[0] = 1;
	num[1] = 2;
	for (int i = 2; i < n; i++) {
		num[i] = num[i - 1] + num[i - 2];
	}
	
	cout << num[n - 1] << endl;
		
	return 0;
}
