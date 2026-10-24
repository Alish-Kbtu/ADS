#include <iostream>
using namespace std;

int main() {
    long long a, s = 2;
    cin >> a;

    while (s * s <= a) {
        while (a % s == 0) {
            a /= s;
            cout << s << " ";
        }
        s += 1;
    }

    if (a > 1) {
        cout << a;
    }
}