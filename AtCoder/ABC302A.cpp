#include <iostream>

using namespace std;

int main()
{
    long long a;
    long long b;
    cin >> a >> b;

    cout << a / b + ((a % b) != 0) << endl;

    return 0;
}