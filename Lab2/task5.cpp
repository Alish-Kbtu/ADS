#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a;
    cin >> a;
    vector<int> v(a);
    for (int i = 0; i < a; i++){
        cin >> v[i];
    }

    int b = (a - 1) / 2;
    if (v.size() % 2 == 1){
        v.erase(v.begin() + b);
    }
    else{
        v.erase(v.begin() + a / 2);
    }

    for (int i = 0; i < a - 1; i++){
        cout << v[i] << " ";
    }
}