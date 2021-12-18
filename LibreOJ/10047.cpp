#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

const int maxS = 15001;
char s[maxS];
int kmp[maxS] = {0}; 

int main() 
{
    scanf("%s", s + 1);
    int k = 0;
    cin >> k;
    int n = strlen(s + 1);

    int result = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            kmp[j] = i - 1;
        }

        int idx = i - 1;
        for (int j = i + 1; j <= n; j++) {
            while (idx >= i && s[j] != s[idx + 1]) {
                idx = kmp[idx];
            }

            if (s[j] == s[idx + 1]) {
                idx++;
            }

            kmp[i] = idx;
        }

        for (int j = i + 2 * k; j <= n; j++) {
            int idx = j;
            while ((kmp[idx] - i + 1) * 2 >= j - i + 1 && kmp[idx] - i + 1 >= k) {
                idx = kmp[idx];
            }
            if (kmp[idx] - i + 1 >= k) {
                result++;
            }
        }
    }

    cout << result << endl;
}