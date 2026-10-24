#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> boris, nursik;
    int x;

    for (int i = 0; i < 5; i++) {
        cin >> x;
        boris.push(x);
    }
    for (int i = 0; i < 5; i++) {
        cin >> x;
        nursik.push(x);
    }

    int moves = 0;

    while (!boris.empty() && !nursik.empty()) {
        int b = boris.front();
        boris.pop();
        int n = nursik.front();
        nursik.pop();

        bool borisWins;

        if (b == 0 && n == 9) {
            borisWins = true;
        }
        else if (n == 0 && b == 9) {
            borisWins = false;
        }
        else if (b > n) {
            borisWins = true;
        }
        else {
            borisWins = false;
        }

        if (borisWins) {
            boris.push(b);
            boris.push(n);
        }
        else {
            nursik.push(b);
            nursik.push(n);
        }

        moves++;
    }

    if (boris.empty()) {
        cout << "Nursik " << moves;
    }
    else {
        cout << "Boris " << moves;
    }
}   