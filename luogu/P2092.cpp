#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

queue<long long> q;

int main()
{
    long long n = 0;
    cin >> n;

    for (long long i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            q.push(i);
            n /= i;
        }
    }

    if (n != 1) {
        q.push(n);
    }

    if (q.size() == 2) {
        cout << 2 << endl;
    } else if (q.size() == 1) {
        cout << 1 << endl << 0 << endl;
    } else {
        long long result = 0;
        result = q.front();
        q.pop();
        cout << 1 << endl << result * q.front() << endl;
    }

    return 0;
}