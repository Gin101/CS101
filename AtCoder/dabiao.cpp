#include <iostream>
#include <algorithm>

using namespace std;

#define int long long
const int maxPrime = 1e6;
int primes[maxPrime] = {0};
int result[3000000] = {0};
bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

signed main()
{
    int idx = 0;
    for (int i = 2; i <= maxPrime; i++) {
        if (is_prime(i)) {
            primes[idx++] = i;
        }
    }

    int idx2 = 0;
    for (int i = 0; i < idx; i++) {
        int a = primes[i];
        if (a * a * primes[i + 1] * primes[i + 2] * primes[i + 2] > 1e12) {
            break;
        }
        for (int j = i + 1; j < idx; j++) {
            int b = primes[j];

            if (a * a * b * primes[j + 1] * primes[j + 1] > 1e12) {
                break;
            }
            for (int k = j + 1; k < idx; k++) {
                int c = primes[k];
                int x = a * a * b * c * c;
                if (x <= 1e12) {
                    result[idx2++] = x;
                } else {
                    break;
                }
            }
        }
    }

    sort(result, result + idx2);

    for (int i = 0; i < idx2; i++) {
        cout << result[i] << ',';
    }
    cout << endl;

    return 0;
}