#include <iostream>

using namespace std;

const int maxN = 3e5 + 1;

long long as[maxN] = {0};
long long bs[maxN] = {0};
long long cs[maxN] = {0};

int main()
{
    int n = 0;
    cin >> n;

    long long result = 0;
    for (int i = 1; i <= n; i++) {
        long long a = 0;
        cin >> a;

        as[a]++;
        bs[i] = i - as[a];

        result += (as[a] - 1) * bs[i] - cs[a];
        cs[a] += bs[i];
    }
	
    cout << result << endl;  

    return 0;
}