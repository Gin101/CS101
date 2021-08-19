#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    if (n % 2 == 1) {
        cout << -1 << endl;

        return 0;
    }

    while (n != 0) {
        int num = 0;
        while (pow(2, num) <= n) {
            num++;
        }
        
        cout << int(pow(2, num - 1)) << ' ';
        n -= pow(2, num - 1);
    }
    
    cout << endl;

    return 0;
}