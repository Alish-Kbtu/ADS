#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a;
    vector<int> l(a + 1, 0);
    vector<int> r(a + 1, 0);

    for (int i = 0; i < a - 1; i++){
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 0){
            l[x] = y;
        } else {
            r[x] = y;
        }
    }

    vector<int> cur;
    cur.push_back(1);
    int mx = 0;

    while (!cur.empty()){
        if (cur.size() > mx){
            mx = cur.size();
        }

        vector<int> nxt;
        for (int i = 0; i < cur.size(); i++){
            int n = cur[i];
            if (l[n] != 0){
                nxt.push_back(l[n]);
            }
            if (r[n] != 0){
                nxt.push_back(r[n]);
            }
        }
        cur = nxt;
    }
    cout << mx;
}