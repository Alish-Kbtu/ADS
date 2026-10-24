#include <iostream>
#include <vector>
using namespace std;

vector<int> l, r;

int sz(int n){
    if (n == 0){
        return 0;
    }
    return 1 + sz(l[n]) + sz(r[n]);
}

int main() {
    int a, b;
    cin >> a;
    vector<int> v(a + 1);
    l.resize(a + 1, 0);
    r.resize(a + 1, 0);

    int c = 0;
    for (int i = 0; i < a; i++){
        int x;
        cin >> x;

        if (c == 0){
            c = 1;
            v[1] = x;
            continue;
        }

        int cur = 1;
        while (true){
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
    }

    cin >> b;
    int cur = 1;
    while(v[cur] != b){
        if (b < v[cur]){
            cur = l[cur];
        } else if (b > v[cur]){
            cur = r[cur];
        }
    }
    cout << sz(cur);
}