#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;
    int c = 1;

    while (count < n) {
        c += 1;

        bool d = true;
        for (int i = 2; i * i <= c; i++) {
            if (c % i == 0) {
                d = false;
                break;
            }
        }

        if (d) {
            count += 1;
        }
    }

    cout << c;
}