#include <iostream>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        int k = 0;
        cin >> n >> k;

        int result = 1;
        for (int j = 0; j < n; j++) {
            int x = 0;
            cin >> x;

            x == result && result++;
        }
        
        cout << (n - result + k) / k << endl;
    }
	
    return 0;
}