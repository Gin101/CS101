#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    int k = 0;
    cin >> n >> k;

    if (k == 2) {
        cout << n / 2 << endl;
    } else if (k == 3) {
        int result = 0;
        for (int i = 1; i <= n; i++) {
            if (i + i > n) {
                break;
            }
            for (int j = i; j <= n; j++) {
                if (i + j + j > n) {
                    break;
                }
                for (int l = j; l <= n; l++) {
                    if (i + j + l == n) {
                        result++;
                    } else if (i + j + l > n) {
                        break;
                    }
                }
            }
        }
        cout << result << endl;
    } else if (k == 4) {
        int result = 0;
        for (int i = 1; i <= n; i++) {
            if (i + i > n) {
                break;
            }
            for (int j = i; j <= n; j++) {
                if (i + j + j + j > n) {
                    break;
                }
                for (int l = j; l <= n; l++) {
                    if (i + j + l + l > n) {
                        break;
                    }
                    for (int m = l; m <= n; m++) {
                        if (i + j + l + m == n) {
                            result++;
                        } else if (i + j + l + m > n) {
                            break;
                        }
                    }
                }
            }
        }
        cout << result << endl;
    } else if (k == 5) {
        int result = 0;
        for (int i = 1; i <= n; i++) {
            if (i + i > n) {
                break;
            }
            for (int j = i; j <= n; j++) {
                if (i + j + j > n) {
                    break;
                }
                for (int l = j; l <= n; l++) {
                    if (i + j + l + l > n) {
                        break;
                    }
                    for (int m = l; m <= n; m++) {
                        if (i + j + l + m + m > n) {
                            break;
                        }
                        for (int o = m; o <= n; o++) {
                            if (i + j + l + m + o == n) {
                                result++;
                            } else if (i + j + l + m + o > n) {
                                break;
                            }
                        }
                    }
                }
            }
        }
        cout << result << endl;
    } else {
        int result = 0;
        for (int i = 1; i <= n; i++) {
            if (i + i > n) {
                break;
            }
            for (int j = i; j <= n; j++) {
                if (i + j + j > n) {
                    break;
                }
                for (int l = j; l <= n; l++) {
                    if (i + j + l + l > n) {
                        break;
                    }
                    for (int m = l; m <= n; m++) {
                        if (i + j + l + m + m > n) {
                            break;
                        }
                        for (int o = m; o <= n; o++) {
                            if (i + j + l + m + o + o > n) {
                                break;
                            }
                            for (int p = o; p <= n; p++) {
                                if (i + j + l + m + o + p == n) {
                                    result++;
                                } else if (i + j + l + m + o + p > n) {
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << result << endl;
    }

    return 0;
}