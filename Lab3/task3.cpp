#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum += a;
        v[i] = sum;
    }

    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;

        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (v[mid] >= b) r = mid;
            else l = mid + 1;
        }
        cout << l + 1 << '\n';
    }
}