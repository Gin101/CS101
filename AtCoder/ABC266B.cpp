#include <iostream>

using namespace std;

int main()
{
	long long n = 0;
	cin >> n;	
	
    cout << (n % 998244353 + 998244353) % 998244353 << endl;
	
	return 0;
}