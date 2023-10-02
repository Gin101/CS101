#include <iostream>
#include <string>

using namespace std;

const int maxN = 1000;
char s[maxN];
int result[maxN] = {0};
int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    if (s[1] == 'q') {
        result[0] = 1;
    } 
    if (s[n - 2] == 'p') {
        result[n - 1] = 1;
    }

    for (int i = 1; i < n - 1; i++) {
        int cnt = 0;
        if (s[i - 1] == 'p') {
            cnt++;
        }
        if (s[i + 1] == 'q') {
            cnt++;
        }
        result[i] = cnt;
    }

    int result0 = 0;
    int result1 = 0;
    int result2 = 0;
    for (int i = 0; i < n; i++) {
        if (result[i] == 0) {
            result0++;
        } else if (result[i] == 1) {
            result1++;
        } else {
            result2++;
        }
    }

    cout << result0 << ' ' << result1 << ' ' << result2 << endl;

    return 0;
}