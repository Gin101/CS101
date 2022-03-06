#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int maxLen = 1e6;
struct BigInt {
	int l = 0;
	int d[maxLen] = {0};
};

istream &operator>>(istream &_cin, BigInt &x) {
	string s;
	_cin >> s;
	for (int i = 0; i < s.size(); i++) {
		x.d[i] = s[s.size() - 1 - i] - '0';
	}
		
	x.l = s.size();
	
	return _cin;
}

ostream &operator<<(ostream &_cout, const BigInt &x) {
	for (int i = x.l - 1; i >= 0; i--) {
		_cout << x.d[i];
	}
	
	return _cout;
}

BigInt operator*(BigInt x, BigInt y) {
	BigInt pro;
	
	for (int i = 0; i < x.l; i++) {
		for (int j = 0; j < y.l; j++) {
			pro.d[i + j] += x.d[i] * y.d[j];
		}
	}
	
	for (int i = 0; i < x.l + y.l - 1; i++) {
		pro.d[i + 1] += pro.d[i] / 10;
		pro.d[i] %= 10;
	}
	
	if (pro.d[x.l + y.l - 1] == 0) {
		pro.l = x.l + y.l - 1;
	} else {
		pro.l = x.l + y.l;
	}
	
	return pro;
}

int main() 
{
	BigInt a;
	BigInt b;
	cin >> a >> b;
	
	cout << a * b << endl;
		
    return 0;
}