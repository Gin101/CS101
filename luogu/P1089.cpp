#include <iostream>

using namespace std;

int main()
{
    int haveMoney = 0;
    int bankMoney = 0;
    int outMoney[12] = {0};

    for (int i = 0; i < 12; i++) {
        cin >> outMoney[i];
    }

    for (int i = 0; i < 12; i++) {
        haveMoney += 300;

        if (haveMoney < outMoney[i]) {
            cout << '-' << i + 1 << endl;
            return 0;
        }

        haveMoney -= outMoney[i];
        int count = haveMoney / 100;
        if (count > 0) {
            int deposit = count * 100;
            bankMoney += deposit;
            haveMoney -= deposit;
        }
    }

    cout << bankMoney * 1.2 + haveMoney << endl;

    return 0;
}