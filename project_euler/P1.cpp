#include <cstdio>

using namespace std;

int main()
{
    int result = 0;
    for (int i = 0; i < 1000; i++) {
        if (i % 3 == 0) {
            result += i;
        } else if (i % 5 == 0) {
            result += i;
        }
    }

    printf("%d\n", result);

    return 0;
}