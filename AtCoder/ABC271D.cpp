#include <iostream>
#include <map>

using namespace std;

map<int, string> dp{{0, " "}};

int main()
{
    int n = 0;
    int s = 0;
    cin >> n >> s;

    int idx = 0;
    string str;
    for (int i = 0; i < n; i++) {
        int a = 0;
        int b = 0;
        cin >> a >> b;

        map<int, string> tmp;
        for (const auto&[idx, str] : dp) {
            tmp[idx + a] = str + 'H';
            tmp[idx + b] = str + 'T';
        }
        dp = tmp;
        
    }

    if (dp.count(s)) {
        cout << "Yes" << endl << dp[s] << endl;
    } else {
        cout << "No" << endl;
    }
  
    return 0;
}