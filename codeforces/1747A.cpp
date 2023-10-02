#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    int t = 0;
    int n = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;

        long long result = 0;
        for (int j = 0; j < n; j++) {
            long long a = 0;
            cin >> a;

            result += a;
        }
        cout << abs(result) << endl;
    }

    return 0;
}
