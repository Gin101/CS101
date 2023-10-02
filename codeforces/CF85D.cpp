#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int main() 
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;
        if (op[0] == 's') {
            long long result = 0;
            for (int i = 2; i < v.size(); i += 5) {
                result += v[i];
            }
            cout << result << endl;
        } else {
            int x = 0;
            cin >> x;

            if (op[0] == 'a') {
                v.insert(lower_bound(v.begin(), v.end(), x), x);
            } else {
                v.erase(lower_bound(v.begin(), v.end(), x));
            }
        }
    }

	return 0;
}