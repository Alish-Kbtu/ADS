#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    vector<int> v(a);
    for (int i = 0; i < a; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    if (b > a){
        cout << -1;
    } else {
        cout << v[b - 1];
    }
}