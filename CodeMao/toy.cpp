#include <iostream>
#include <string>

using namespace std;


const int maxN = 1e5;
struct Toy {
    int dir = 0;
    string name;
} t[maxN];

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> t[i].dir >> t[i].name;
    }

    int idx = 0;
    for (int i = 0; i < m; i++) {
        int a = 0;
        int s = 0;
        cin >> a >> s;

        s %= n;
        if (a == t[idx].dir) {
            idx -= s;
            if (idx < 0) {
                idx += n;
            }
        } else {
            idx += s;
            if (idx >= n) {
                idx -= n;
            }
        }
    }

    cout << t[idx].name << endl;

    return 0;
}