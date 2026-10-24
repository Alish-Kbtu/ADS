#include <iostream>
using namespace std;

int main() {
    int a, s = 2;
    bool p = 0;
    cin >> a;

    if (a < 2) {
        p = 1;
    }

    while (s * s <= a) {
        if (a % s == 0) {
            p = 1;
            break;
        }
        s += 1;
    }

    if (p == 1) {
        cout << "NO";
    } else {
        cout << "YES";
    }
}