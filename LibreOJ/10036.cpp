#include <iostream>
#include <string>

using namespace std;

const int maxS = 400001;
int h[maxS] = {0};
int num[maxS] = {0};
const int P = 131;
const int MOD = 1000000007;

int main() 
{
    for (int i = 0; i < 2; i++) {
        string s;
        cin >> s;
        
        num[0] = 1;
        for (int i = 1; i <= s.size(); i++) {
            h[i] = (h[i - 1] * 131 + s[i] - 'a') % MOD;
            num[i] = num[i - 1] * 131 % 1;
        }

        for (int i = 1; i <= s.size(); i++) {
            if (h[i] == (h[s.size()] - h[s.size() - i] * num[i] % MOD) % MOD) {
                cout << i << ' ';
            }
        }
        cout << endl;
    }
}