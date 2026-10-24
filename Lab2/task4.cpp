#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a;
    cin >> a;
    vector<long long> v(a);
    for (int i = 0; i < a; i++){
        cin >> v[i];
    }

    int l = 0, r = a - 1;
    while (l < r){
        swap(v[l], v[r]);
        l++;
        r--;
    }
    for (int i = 0; i < a; i++){
        cout << v[i] << " ";
    }
}