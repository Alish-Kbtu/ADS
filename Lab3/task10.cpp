#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    vector<int> v(a);
    for (int i = 0; i < a; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        v[i] = max(x2, y2);
    }
    sort(v.begin(), v.end());
    cout << v[b - 1];
}