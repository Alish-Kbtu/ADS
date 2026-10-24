#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a;
    cin >> a;
    vector<char> v(a);
    for (int i = 0; i < a; i++){
        cin >> v[i];
    }
    char k;
    cin >> k;

    bool f = false;
    for (int i = 0; i < a; i++){
        if (v[i] > k){
            cout << v[i];
            f = true;
            break;
        }
    }
    if (!f){
        cout << v[0];
    }
}