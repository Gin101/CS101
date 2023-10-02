#include <iostream>
#include <vector>

using namespace std;

const int maxN = 2e5 + 1;
int a[maxN] = {0};
int b[maxN] = {0};
int num[maxN] = {0};
vector<int> v[maxN];
int main() 
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;

        for (int j = 1; j <= n; j++) {
            v[j].clear();
        }

        for (int j = 1; j <= n; j++) {
            cin >> a[j];

            v[a[j]].push_back(j);
        }

        int idx = 0;
        bool flag = true;
        for (int j = n; j >= 1; j--) {
            if (v[j].size() > 2) {
                cout << "NO" << endl;
                flag = false;
                break;
            } else if (v[j].size() == 2) {
                a[v[j][0]] = j;
                b[v[j][1]] = j;
                num[++idx] = j;
            } else if (v[j].size() == 1) {
                a[v[j][0]] = j;
                b[v[j][0]] = j;
            } else {
                if (!idx) {
                    cout << "NO" << endl;
                    flag = false;
                    break;
                }
                b[v[num[idx]][0]] = j;
                a[v[num[idx]][1]] = j;
                idx--;
            }
        } 
        
        if (flag) {
            cout << "YES" << endl;
            for (int j = 1; j <= n; j++) {
                cout << a[j] << ' ';
            }
            cout << endl;
            for (int j = 1; j <= n; j++) {
                cout << b[j] << ' ';
            }
            cout << endl;
        }
    }
    
    return 0;
}