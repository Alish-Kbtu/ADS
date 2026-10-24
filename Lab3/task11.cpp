#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> q(t);
    for (int i = 0; i < t; i++){
        cin >> q[i];
    }

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    for (int k = 0; k < t; k++){
        int x = q[k];
        int l = 0, r = n * m - 1;
        bool found = false;

        while (l <= r){
            int p = (l + r) / 2;
            int i = p / m;
            int j;
            if (i % 2 == 0) j = p % m;
            else j = m - 1 - p % m;

            if (a[i][j] == x){
                cout << i << " " << j << '\n';
                found = true;
                break;
            } else if (a[i][j] > x){
                l = p + 1;
            } else {
                r = p - 1;
            }
        }
        if (!found) cout << -1 << '\n';
    }
}