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

    for (int i = 0; i < a; i+=2){
        cout << v[i] << " ";
    }
}