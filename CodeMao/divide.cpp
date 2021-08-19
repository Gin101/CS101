#include <iostream>

using namespace std;

struct Node {
    int val = 0;
    Node* next;
}p;

int main()
{
    int n = 0;
    int type = 0;
    cin >> n >> type;

    long long result = 0;
    if (type == 0) {
       for (int i = 0; i < n; i++) {
           int a = 0;
           cin >> a;

           result += a * a;
       }
    }

    cout << result << endl;

    return 0;
}