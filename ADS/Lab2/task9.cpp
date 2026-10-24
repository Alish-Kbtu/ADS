#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    deque<string> d;
    string cmd;

    while (cin >> cmd) {
        if (cmd == "add_front") {
            string t;
            cin >> t;
            d.push_front(t);
            cout << "ok\n";
        } else if (cmd == "add_back") {
            string t;
            cin >> t;
            d.push_back(t);
            cout << "ok\n";
        } else if (cmd == "erase_front") {
            if (d.empty()) {
                cout << "error\n";
            } else {
                cout << d.front() << "\n";
                d.pop_front();
            }
        } else if (cmd == "erase_back") {
            if (d.empty()) {
                cout << "error\n";
            } else {
                cout << d.back() << "\n";
                d.pop_back();
            }
        } else if (cmd == "front") {
            if (d.empty()) cout << "error\n";
            else cout << d.front() << "\n";
        } else if (cmd == "back") {
            if (d.empty()) cout << "error\n";
            else cout << d.back() << "\n";
        } else if (cmd == "clear") {
            d.clear();
            cout << "ok\n";
        } else if (cmd == "exit") {
            cout << "goodbye\n";
            break;
        }
    }
}