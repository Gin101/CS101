#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;

        int result = n;
        vector<int> p(n + 1);
        vector<int> b(n + 1);
        vector<int> a(n + 1);

        for (int j = 1; j <= n; j++) {
            cin >> a[j];
            p[a[j]] = j;
        }
        for (int j = 1; j <= n; j++) {
            if (!b[j]) {
                result--;
                for (int k = j; !b[k]; b[k] = j, k = a[k]);
            }
        }
        result++;
        for (int j = 1; j < n; j++) {
            if (b[p[j]] == b[p[j + 1]]) {
                result -= 2;
                break;
            }
        }

        cout << result << endl;
    }
	
    return 0;
}