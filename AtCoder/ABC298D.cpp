#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxLen = 6e5;
struct BigInt {
	int l = 0;
	int d[maxLen] = {0};
	
	BigInt() {
		l = 0;
		memset(d, 0, sizeof(d));
	}	
	BigInt(int x) {
		l = 0;
		while (x > 0) {
			d[l++] = x % 10;
			x /= 10;
		}
	}
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

bool operator<(BigInt x, BigInt y) {
	if (x.l != y.l) {
		return x.l < y.l;
	}
	for (int i = x.l - 1; i >= 0; i--) {
		if (x.d[i] != y.d[i]) {
			return x.d[i] < y.d[i];
		}
	}
		
	return false;
}

BigInt operator+(BigInt x, BigInt y) {
	BigInt sum;
	
	for (int i = 0; i < max(x.l, y.l); i++) {
		sum.d[i + 1] = (sum.d[i] + x.d[i] + y.d[i]) / 10;
		sum.d[i] = (sum.d[i] + x.d[i] + y.d[i]) % 10;
	}
	
	if (sum.d[max(x.l, y.l)] != 0) {
		sum.l = max(x.l, y.l) + 1;
	} else {
		sum.l = max(x.l, y.l);
	}
	
	return sum;
}

BigInt operator-(BigInt x, BigInt y) {
	BigInt dif;
	for (int i = 0; i < x.l; i++) {
		if (x.d[i] < y.d[i]) {
			x.d[i] += 10;
			x.d[i + 1]--;
		}
		dif.d[i] = x.d[i] - y.d[i];
	}
	
	dif.l = x.l;
	
	while (dif.l > 0 && dif.d[dif.l - 1] == 0) {
		dif.l--;
	}
		
	return dif;
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

BigInt operator/(BigInt x, BigInt y) {
	BigInt l = BigInt(0);
	BigInt r = x + BigInt(1);
	while (l + BigInt(1) < r) {
		BigInt m = l + r;
		for (int i = m.l - 1; i > 0; i--) {
			m.d[i - 1] += ((m.d[i] % 2) * 10);
			m.d[i] /= 2;
		}
		m.d[0] /= 2;
		
		if (m.d[m.l - 1] == 0) {
			m.l--;
		}
		
		if (x < m * y) {
			r = m;
		} else {
			l = m;
		}
	}
	
	return l;
}

BigInt operator%(BigInt x, BigInt y) {
	return x - (y * (x / y));
}

int main() 
{
	int q = 0;
    cin >> q;

    BigInt result = 1;
    BigInt digit = 10;
    BigInt MOD = 998244353;
    int cnt = 0;
    for (int i = 0; i < q; i++) {
        int op = 0;
        cin >> op;

        if (op == 1) {
            BigInt x = 0;
            cin >> x;

            result = result * digit;
            result = result + x;
            cnt++;
        } else if (op == 2) {
            BigInt tmp = 1;
            for (int j = 0; j < cnt; j++) {
                tmp = tmp * digit;
            }
            result = result % tmp;
            cnt--;
        } else {
            cout << result % MOD << endl;
        }
    }
	
    return 0;
}