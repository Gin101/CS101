#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int maxN = 2e5;
int c[maxN] = {0};
char result[maxN];

int main()
{
    int n = 0;
    int m = 0;
    string s;
    cin >> n >> m >> s;

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    for (int i = 1; i <= m; i++) {
        int first = -1;
        int pre = 0;
        int last = 0;
        for (int j = 0; j < n; j++) {
            if (c[j] == i) {
                if (first == -1) {
                    first = j;
                    pre = j;
                    last = j;
                } else {
                    result[j] = s[pre];
                    pre = j;
                    last = j;
                }
            }
        }

        result[first] = s[last];
    }

    for (int i = 0; i < strlen(result); i++) {
        cout << result[i];
    }
    cout << endl;

    return 0;
}