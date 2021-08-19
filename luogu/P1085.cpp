#include <iostream>

using namespace std;

int main()
{
    int maxTime = 0;
    int maxI = 0;

    for (int i = 1; i <= 7; i++) {
        int time = 0;
        int time2 = 0;
        int time3 = 0;
        cin >> time2 >> time3;
        time = time2 + time3;
        if (time < 8) {
            continue;
        }
        
        if (time > maxTime) {
            maxTime = time;
            maxI = i;
        }
    }

    cout << maxI << endl;
    return 0;
}