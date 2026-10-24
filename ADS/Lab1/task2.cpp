#include <iostream>
using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;

    a %= c;
    long long r = 1 % c;

    while(b > 0) {
        if(b % 2 == 1) {
            r = r * a % c;
        }
        a = a * a % c;
        b /= 2;
    }
    cout << r;
}