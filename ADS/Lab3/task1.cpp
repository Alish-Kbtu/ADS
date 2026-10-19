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
    int x;
    cin >> x;

    int l = 0, r = a - 1;
    bool b = false; 
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (v[mid] == x) {
            b = true;
            break;
        } else if (v[mid] < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
}