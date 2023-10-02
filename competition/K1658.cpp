#include <iostream>
using namespace std;

int a,ans,cnt;

int main()
{
    int a = 0;
    cin >> a;

    for (int i = a; i > 0; i++) {
        int x = 0;
        int tmp = i;

        while (tmp) {
            x += tmp % 10;
            tmp /= 10;
        }
        if (i % x == 0) {
            cout << i << endl;
            break;
        }
    }
	
	return 0;
}