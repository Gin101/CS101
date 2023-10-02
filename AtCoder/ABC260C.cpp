#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    long long x = 0;
    long long y = 0;
    cin >> n >> x >> y;

    long long tmp = 1;
    long long result = 0;
	for (int i = 0; i < n - 1; i++) {
        result += tmp * x;
        tmp += result;
        result *= y;
	}

    cout << result << endl;

    return 0;
}