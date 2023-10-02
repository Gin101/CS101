#include <iostream>

using namespace std;

int main()
{
    long long x = 0;
    long long k = 0;
    cin >> x >> k;

    long long tmp = 1;
    for (int i = 0; i < k; i++) {
        tmp *= 10;
        x = (x + tmp / 2) / tmp * tmp;
    }
	
    cout << x << endl;
}