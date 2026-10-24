#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    deque<string> d;
    for (int i = 0; i < a; i++){
        string p;
        cin >> p;
        d.push_back(p);
    }

    for (int i = 0; i < b; i++){
        d.push_back(d.front());
        d.pop_front();
    }

    for (int i = 0; i < a; i++){
        cout << d[i] << " ";
    }
}
