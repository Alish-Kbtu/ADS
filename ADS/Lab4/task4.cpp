#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a;
    cin >> a;
    vector<int> v(a + 1);
    vector<int> l(a + 1, 0);
    vector<int> r(a + 1, 0);
    vector<int> sum(a, 0);

    int c = 0, mx = 0;
    for (int i = 0; i < a; i++){
        int x;
        cin >> x;

        if (c == 0){
            c = 1;
            v[1] = x;
            sum[0] += x;
            continue;
        }

        int cur = 1, dep = 0;
        while (true){
            dep++;
            if (x < v[cur]){
                if (l[cur] == 0){
                    c++;
                    v[c] = x;
                    l[cur] = c;
                    break;
                }
                cur = l[cur];
            } else {
                if (r[cur] == 0){
                    c++;
                    v[c] = x;
                    r[cur] = c;
                    break;
                }
                cur = r[cur];
            }
        }

        sum[dep] += x;
        if (dep > mx){
            mx = dep;
        }
    }

    cout << mx + 1 << "\n";
    for (int i = 0; i < mx; i++){
        cout << sum[i] << " ";
    }
}