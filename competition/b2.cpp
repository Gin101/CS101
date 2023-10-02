#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>

using namespace std;

const int maxLen = 1e6;
struct BigInt {
	int l = 0;
	int d[maxLen] = {0};
};

ostream &operator<<(ostream &_cout, const BigInt &x) {
	for (int i = x.l - 1; i >= 0; i--) {
		_cout << x.d[i];
	}
	
	return _cout;
}

BigInt operator*(BigInt x, int y) {
	BigInt pro;
	
	for (int i = 0; i < x.l; i++) {
		pro.d[i] += (x.d[i] * y);
		pro.d[i + 1] += (pro.d[i] / 10);
		pro.d[i] %= 10;
	}
	
	pro.l = x.l;
	while (pro.d[pro.l]) {
		pro.d[pro.l + 1] += (pro.d[pro.l] / 10);
		pro.d[pro.l] %= 10;
		pro.l++;
	}
	
	return pro;
}

int main() 
{
    freopen("b2.in", "r", stdin);
    freopen("b2.out", "w", stdout);

	int n = 0;
    int m = 0;
	cin >> n >> m;
	
	BigInt result;
	result.l = 1;
	result.d[0] = 1;
	for (int i = m + 1; i <= n; i++) {
		result = result * i;
        result = result * i;
	}

	cout << result << endl;
		
    return 0;
}