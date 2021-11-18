#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int numa[26] = {0};
int numb[26] = {0};

int main()
{
    int q = 0;
    cin >> q;

    for (int i = 0; i < q; i++) {
        memset(numa, 0, sizeof(numa));
        memset(numb, 0, sizeof(numb));

        int n = 0;
        cin >> n;

        string a;
        string b;
        cin >> a >> b;

        for (int j = 0; j < n; j++) {
            numa[a[j] - 'a']++;
            numb[b[j] - 'a']++;
        }

        bool flag = true;
        for (int j = 0; j < 26; j++) {
            if (numa[j] != numb[j]) {
                flag = false;
                cout << "NO" << endl;
                break;
            }
        }

        if (flag) {
            bool flag2 = true;
            for (int j = 0; j < 26; j++) {
                if (numa[j] > 1) {
                    cout << "YES" << endl;
                    flag2 = false;
                    break;
                }
            }

            if (flag2) {
                int cnta = 0;
                int cntb = 0;
                for (int j = 0; j < n; j++) {
                    for (int k = j + 1; k < n; k++) {
                        if (a[k] < a[j]) {
                            cnta++;
                        }

                        if (b[k] < b[j]) {
                            cntb++;
                        }
                    }
                }

                if (cnta % 2 == cntb % 2) {
                    cout << "YES" << endl; 
                } else {
                    cout << "NO" << endl;
                }
            }
        }
    }

    return 0;
}