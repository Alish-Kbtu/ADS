#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    vector<int> v(a);
    int m;
    for (int i = 0; i < a; i++){
        cin >> v[i];
        if (v[i] > m){
            m = v[i];
        }
    }

    int l = 1, r = m;
    while( l < r){
        int k = (l + r) / 2;

        int c = 0;
        for (int i = 0; i < a; i++){
            c += (v[i] + k - 1) / k;
        }
        if (c <= b){
            r = k;
        } else {
            l = k + 1;
        }
    }
    cout << l;
}