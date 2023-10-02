#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool flag[26] = {false};

int main()
{
    int n1 = 0;
    int n2 = 0;
    string ant1;
    string ant2;
    int t = 0;
    cin >> n1 >> n2 >> ant1 >> ant2 >> t;

    string result;
    for (int i = 0; i < n1; i++) {
        flag[ant1[i] - 65] = true;
        result += ant1[n1 - i - 1];
    }

    for (int i = 0; i < n2; i++) {
        result += ant2[i];
    }

    for (int i = 0; i < t; i++) {
        string tmp = result;
        for (int j = 0; j < n1 + n2 - 1; j++) {
            if (flag[tmp[j] - 65] && !flag[tmp[j + 1] - 65]) {
                swap(result[j], result[j + 1]);
            }
        }
    }

    cout << result << endl;

    return 0;
}