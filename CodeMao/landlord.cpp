#include <iostream>
#include <cstring>

using namespace std;

const int maxC = 15;
int c[maxC] = {0};

int main()
{
    int t = 0;
    int n = 0;
    cin >> t >> n;

    for (int i = 0; i < t; i++) {
        int result = 0;
      	memset(c, 0, sizeof(c));
        for (int j = 0; j < n; j++) {
            int a = 0;
            int b = 0;
            cin >> a >> b;

            if (a == 0) {
                if (b == 0) {
                    c[13]++;
                } else {
                    c[14]++;
                }
            } else {
                c[a - 1]++;
            }
        }

        if (n == 2) {
            if (c[13] > 0 && c[14] > 0) {
                cout << 1 << endl;
                continue;
            }//rocket
            
            for (int i = 0; i <= 14; i++) {
                if (c[i] == 1) {
                    cout << 2 << endl;
                    break;
                } else if (c[i] == 2) {
                    cout << 1 << endl;
                    break;
                }
            }
        } else if (n == 3) {
            if (c[13] > 0 && c[14] > 0) {
                cout << 2 << endl;
                continue;
            }//rocket
            
            bool flag = false;
            for (int i = 0; i <= 14; i++) {
                if (c[i] == 1) {
                    if (flag) {
                        cout << 3 << endl;
                        break;
                    } else {
                        flag = true;
                    }
                } else if (c[i] == 2) {
                    cout << 2 << endl;
                    break;
                } else if (c[i] == 3) {
                    cout << 1 << endl;
                    break;
                }
            }
        } else if (n == 4) {
            bool flag = false;
            if (c[13] > 0 && c[14] > 0) {
                flag = true;
            }//rocket

            if (flag) {
                for (int i = 0; i <= 12; i++) {
                    if (c[i] == 1) {
                        cout << 3 << endl;
                        break;
                    } else if (c[i] == 2) {
                        cout << 2 << endl;
                        break;
                    }
                }
            } else {
                bool flag2 = false;
                bool flag3 = false;
                bool flag4 = false;
                for (int i = 0; i <= 14; i++) {
                    if (c[i] == 1) {
                        if (flag2) {
                            cout << 3 << endl;
                            break;
                        } else {
                            if (flag3) {
                                if (flag4) {
                                    cout << 4 << endl;
                                    break;
                                } else {
                                    flag4 = true;
                                }
                            } else {
                                flag3 = true;
                            }
                        }
                    } else if (c[i] == 2) {
                        if (flag3) {
                            cout << 3 << endl;
                            break;
                        }

                        if (flag2) {
                            cout << 2 << endl;
                            break;
                        } else {
                            flag2 = true;
                        }
                    } else if (c[i] == 3) {
                        cout << 1 << endl;
                        break;
                    } else if (c[i] == 4) {
                        cout << 1 << endl;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}