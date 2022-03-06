#include <iostream>

using namespace std;
 
int num[6] = {0};
 
int main()
{
    for (int i = 0; i < 6; i++) {
        cin >> num[i];
    }

    int first = (num[0] - num[2]) * (num[0] - num[2]) + (num[1] - num[3]) * (num[1] - num[3]);
    int second = (num[0] - num[4]) * (num[0] - num[4]) + (num[1] - num[5]) * (num[1] - num[5]);
    int third = (num[2] - num[4]) * (num[2] - num[4]) + (num[3] - num[5]) * (num[3] - num[5]);
    if ((first + second == third || first + third == second || second + third == first && first) && second && third) {
        cout << "RIGHT" << endl;
        return 0;
    }

    for (int i = 0; i < 6; i++) {
        num[i]--;
        int first = (num[0] - num[2]) * (num[0] - num[2]) + (num[1] - num[3]) * (num[1] - num[3]);
        int second = (num[0] - num[4]) * (num[0] - num[4]) + (num[1] - num[5]) * (num[1] - num[5]);
        int third = (num[2] - num[4]) * (num[2] - num[4]) + (num[3] - num[5]) * (num[3] - num[5]);
        if ((first + second == third || first + third == second || second + third == first) && first && second && third) {
            cout << "ALMOST" << endl;
            return 0;
        }
        num[i] += 2;
        first = (num[0] - num[2]) * (num[0] - num[2]) + (num[1] - num[3]) * (num[1] - num[3]);
        second = (num[0] - num[4]) * (num[0] - num[4]) + (num[1] - num[5]) * (num[1] - num[5]);
        third = (num[2] - num[4]) * (num[2] - num[4]) + (num[3] - num[5]) * (num[3] - num[5]);
        if ((first + second == third || first + third == second || second + third == first) && first && second && third) {
            cout << "ALMOST" << endl;
            return 0;
        }
        num[i]--;
    }
    cout << "NEITHER" << endl;

    return 0;
}