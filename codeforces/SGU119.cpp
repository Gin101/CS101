#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > result;

int main() 
{
    int n = 0;
    int tmpa = 0;
    int tmpb = 0;
    cin >> n >> tmpa >> tmpb;

    int a = n / __gcd(tmpa, n);
    int b = n / __gcd(tmpb, n);
    int idx = a * b / __gcd(a, b);
    for (int i = 1; i <= idx; i++) {
        result.push_back(make_pair(i * tmpa % n, i * tmpb % n));
    }
	
    sort(result.begin(), result.end());

    cout << idx << endl;
    for (int i = 0; i < idx; i++) {
        cout << result[i].first << ' ' << result[i].second << endl;
    }

	return 0;
}
