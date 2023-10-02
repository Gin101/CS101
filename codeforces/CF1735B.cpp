#include <iostream>
 
using namespace std;


int main()
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        int tmp = 0;
        cin >> n >> tmp;

        int result = 0;
        for (int j = 1; j < n; j++) {
            int a = 0;
            cin >> a;

            result += (a - 1) / (2 * tmp - 1);
        }

        cout << result << endl;
    }

    return 0;
}