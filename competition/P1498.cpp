#include <iostream>
#include <cstring>

using namespace std;

const int maxLen = 1024;
int flag[1024] = {1};

int main()
{
    int n = 0;
	cin >> n;

    for (int i = 0; i < 1 << n ; i++) {
        for (int j = 1; j < (1 << n) - i; j++) {
            cout << " ";
        }
		for (int j = i; j >= 0; j--) {
            flag[j] ^= flag[j - 1];
        }
		if (!(i % 2)) {
            for (int j = 0; j <= i; j++) {
                cout << (flag[j] ? "/\\" : "  ");
            }
        } else {
            for (int j = 0; j <= i; j+=2) {
                cout << (flag[j] ? "/__\\" : "    ");
            }
        }
		
		cout << endl ;
    }

    return 0;
}