#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int maxN = 1e7 + 1;
long long read() {
    long long result = 0;
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

    return result;
}

bool flag[maxN] = {false};
int main() 
{
    long long p = read();
    long long n = read();

    flag[1] = true;
    long long sum = 1;
    long long result = 1;
    for (register int i = 1; i <= n; ++i) {
        sum = (sum + i) % p;
        if (!sum) {
            sum++;
        }
        if (!flag[sum]) {
            result++;
            flag[sum] = true;
        }
    }
	
    printf("%lld\n", result);

	return 0;
}