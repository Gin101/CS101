#include <iostream>
#include <vector>

using namespace std;

const int maxN = 2e5;
vector<int> num[maxN];

int main()
{
    int n = 0;
    int q = 0;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        int l = 0;
        cin >> l;

        for (int j = 0; j < l; j++) {
            int a = 0;
            cin >> a;

            num[i].push_back(a);
        }
    }

    for (int i = 0; i < q; i++) {
        int s = 0;
        int t = 0;
        cin >> s >> t;

        cout << num[s - 1][t - 1] << endl;
    }

    return 0;
}