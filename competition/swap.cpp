#include <iostream>
#include <cmath>

using namespace std;

const int maxN = 5e5;
int num[maxN] = {0};

int main()
{
    int n = 0;
    cin >> n;

    int result = 0;
    for (int i = 0; i < n; i++) {
        cin >> num[i];

        result += abs(num[i] - (i + 1));
    }

    for (int i = 1; i <= n; i++) {
        if (i * (i + 1) == (result * 2)) {
            cout << (i + 1) << endl;
            return 0;
        }
    }



    return 0;
}