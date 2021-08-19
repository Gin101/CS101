#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

bool flag[10] = {false};

void count(long long x) {
	if (x == 0) {
		flag[0] = true;
		return;
	}
	
	while (x > 0) {
		flag[x % 10] = true;
		x /= 10;
	}
}

int main()
{
	freopen("stat.in","r",stdin);
	freopen("stat.out","w",stdout);
	
	long long a = 0;
	long long b = 0;
	
	while (cin >> a >> b) {
		int result = 0;
		memset(flag, 0, sizeof(flag));
		
		count(a);
		count(b);
		count(a * b);
		
		for (int i = 0; i <= 9; i++) {
			if (flag[i]) {
				result++;
			}	
		} 
		
		cout << result << endl;
	}
	
	return 0;
}
