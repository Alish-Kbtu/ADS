#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a;
    cin >> a;
    vector<int> v(a + 1);
    vector<int> l(a + 1, 0);
    vector<int> r(a + 1, 0);

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
            if (v[cur] > x){
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

    int s = 0;
    for (int i = 1; i <= c; i++){
        if (l[i] != 0 && r[i] != 0){
            s++;
        }
    }
    cout << s;
}