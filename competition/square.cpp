#include <iostream>
#include <string>

using namespace std;

bool flag[2] = {false};

unsigned long long read(int idx) {
	unsigned long long result = 0;
	char ch = getchar();
	string s;
    while (ch < '0' || ch > '9') {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        result = result * 10 + (ch ^ 48);
        s += ch;
        ch = getchar();
    }
	
    if (s == "18446744073709551616") {
        flag[idx] ^= 1;
    }

    return result;
}

int main()
{
    int n = 0;
    cin >> n;

    unsigned long long x2 = 0;
    unsigned long long y2 = 0;
    for (int i = 0; i < 4 * n - 1; i++) {
        unsigned long long x = read(0);
        unsigned long long y = read(1);
        x2 ^= x;
        y2 ^= y;
    }
	
    if (flag[0] && x2 == 0) {
        cout << "18446744073709551616" << ' '; 
    } else {
        cout << x2 << ' ';
    }
    if (flag[1] && y2 == 0) {
        cout << "18446744073709551616" << endl;
    } else {
        cout << y2 << endl;
    }

	return 0;
}