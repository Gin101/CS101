#include <iostream>
#include <string>
#include <map>

using namespace std;

const int maxN = 5e5 + 1;
int result[maxN] = {0};
int tmp[maxN] = {0};
map<int, int> mp;
int main()
{
    int q = 0;
    cin >> q;

    result[0] = -1;
    int idx = 0;
    int cnt = 0;
    for (int i = 0; i < q; i++) {
        string x;
        cin >> x;

        if (x == "ADD") {
            int y = 0;
            cin >> y;

            result[++cnt] = y;
            tmp[cnt] = idx;
            idx = cnt;
        }
        if (x == "DELETE" && idx) {
            idx = tmp[idx];
        }
        if (x == "SAVE") {
            int y = 0;
            cin >> y;

            mp[y] = idx;
        }
        if (x == "LOAD") {
            int y = 0;
            cin >> y;

            idx = mp[y];
        }

        cout << result[idx] << ' ';
    }

    cout << endl;
	
	return 0;
}