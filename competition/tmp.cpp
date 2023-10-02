#include <iostream>

using namespace std;

int main()
{
    long long result = 1145141919810;
    int cnt = 0;
    long long real = 0;
    long long tmp = result;
    while (result && cnt < 9) {
        long long power = 1;
        for (int i = 0; i < cnt; i++) {
            power *= 10;
        }

        real += tmp % 10 * power;
        tmp /= 10;
        cnt++;
    }

    if (result >= 1e9 && real < 1e8) {
        for (int i = 10; i < 1e9 / real; i *= 10) {
            cout << '0';
        }
    }

    cout << real << endl;

    return 0;
}