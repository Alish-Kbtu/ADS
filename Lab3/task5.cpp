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

    for (int i = 0; i < b; i++){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int c1 = upper_bound(v.begin(), v.end(), r1) - lower_bound(v.begin(), v.end(), l1);
        int c2 = upper_bound(v.begin(), v.end(), r2) - lower_bound(v.begin(), v.end(), l2);
        int c = c1 + c2;

        int l = max(l1, l2), r = min(r1, r2);
        if (l <= r){
            c -= upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l);
        }
        cout << c << "\n";
    }
}