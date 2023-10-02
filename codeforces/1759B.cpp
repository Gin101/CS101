#include <iostream>
#include <algorithm>

using namespace std;

const int maxA = 50;
int q[maxA] = {0};
int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a = 0;
        int b = 0;
        cin >> a >> b; 

        int sum = 0;
        int result = 0;
        for (int j = 0; j < a; j++) {
            cin >> q[j];
            result = max(result, q[j]);
            sum += q[j];
        }
        while (result * (result + 1) / 2 < sum + b) {
            result++;
        }

        if (result * (result + 1) / 2 == sum + b) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

	return 0;
}