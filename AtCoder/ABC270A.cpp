#include <iostream>

using namespace std;

int exam[3] = {0};
void ope(int num) {
    if (num == 0) {
        return;
    }
    if (num >= 4) {
        exam[2]++;
        ope(num - 4);
    } else if (num >= 2) {
        exam[1]++;
        ope(num - 2);
    } else if (num >= 1) {
        exam[0]++;
        ope(num - 1);
    }
}
int main()
{
    int a = 0;
    int b = 0;
    cin >> a >> b;

    ope(a);
    ope(b);

    int result = 0;
    for (int i = 0; i < 3; i++) {
        if (exam[i] >= 1) {
            result += (2 << i);
        }
    }

    cout << result << endl;

    return 0;
}