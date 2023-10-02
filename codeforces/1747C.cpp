#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;
 
int main() 
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        int a0 = 0;
        cin >> n >> a0;

        int result = INT_MAX;
        for (int i = 1; i < n; i++) {
            int a = 0;
            cin >> a;
            result = min(result, a);
        }

        cout << (result < a0 ? "Alice" : "Bob") << endl;
    }
	
    return 0;
}