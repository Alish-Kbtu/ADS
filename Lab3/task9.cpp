#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    vector<int> v(a);
    int l = 0, r = 0;
    for (int i = 0; i < a; i++){
        cin >> v[i];
        if (v[i] > l){
            l = v[i];
        }
        r += v[i];
    }

    while (l < r){
        int s = (l + r) / 2;
        int p = 1, sum = 0;
        for (int i = 0; i < a; i++){
            if (sum + v[i] > s){
                p++;
            } else {
                sum += v[i];
            }
        }
        if (p <= b){
            r = s;
        } else {
            l = s + 1;
        }
    }
    cout << l;
}