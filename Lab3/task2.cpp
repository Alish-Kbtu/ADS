#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    for (int i = 0; i < q; i++){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int c = 0;
        for (int j = 0; j < n; j++){
            if ((l1 <= v[j] && v[j] <= r1) || (l2 <= v[j] && v[j] <= r2)){
                c++;
            }
        }
        cout << c << "\n";
    }
}