#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 1000001;
char c[maxN] = {0};

int main()
{   
    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    bool flag = true;
    int result = 0;
    for (int i = 2; i <= n; i++) {
        if (c[i] == c[i - 1]) {
            if (!flag) {
                flag = true;
                result++;
            } else {
                flag = false;
            }
        }
    }

    if (!flag) {
        result++;
    }
    cout << result << endl;

    flag = true;
    int start = 0;
    for (int i = 2; i <= n; i++) {
        if (c[i] == c[i - 1]) {
            if (!flag) {
                flag = true;

                cout << start << ' ' << i - 1 << ' ';
                switch (c[start]) {
                    case 'A': {
                        if (c[i - 1] == 'B') {
                            cout << "BAC" << endl;
                        } else {
                            cout << "BCA" << endl;
                        }
                        break;
                    } case 'B': {
                        if (c[i - 1] == 'A') {
                            cout << "BAC" << endl;
                        } else {
                            cout << "ACB" << endl;
                        }
                        break;
                    } case 'C': {
                        if (c[i - 1] == 'A') {
                            cout << "BCA" << endl;
                        } else {
                            cout << "ACB" << endl;
                        }
                    }
                }
            } else {
                flag = false;
                start = i;
            }
        }
    }

    if (!flag) {
        cout << start << ' ' << n << ' ';
        switch (c[start]) {
            case 'A': {
                cout << "BAC" << endl;
                break;
            } case 'B': {
                cout << "BAC" << endl;
                break;
            } case 'C': {
                cout << "ACB" << endl;
            }
        }
    }

    return 0;
}