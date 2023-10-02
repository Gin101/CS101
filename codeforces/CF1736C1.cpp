#include <iostream>

using namespace std;

const int maxN = 2e5 + 1;
long long a[maxN] = {0};

int main()
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;

        long long sum = 0;
        for (int j = 1; j <= n; j++) {
            cin >> a[j];
            if (a[j] > a[j - 1]) {
                a[j] = a[j - 1] + 1;
            }
            sum += a[j];
        }

        cout << sum << ' ';
    }
	
    cout << endl;

    return 0;
}