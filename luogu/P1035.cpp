#include <iostream>

using namespace std;

int main()
{
    int k = 0;
    cin >> k;
    float n = 1;
    double sum = 1;

    while (k > sum) {
        n++;
        sum += 1 / n;
    }

    cout << n;

    return 0;
}