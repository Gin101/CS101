#include <iostream>
#include <cstring>

using namespace std;

const int maxTN = 100;
int p[maxTN] = {0};

int main()
{
    int t = 0;
    int n = 0;
    int m = 0;
    cin >> t >> n >> m;

    for (int i = 0; i < t; i++) {
        cin >> p[i];  
    }

    int result = 0;
    for (int i = 0; i < t - 1; i++) {
        int tmp = 0;
        if (p[i] < p[i + 1]) {
            tmp = m / p[i];
            m /= p[i];

            m += (p[i + 1] * tmp);
        }
    }

    cout << m << endl;

    return 0;
}