#include <iostream>
#include <vector>
using namespace std;

vector<int> v, l, r;
int sum = 0;

void p(int n){
    if (n == 0){
        return;
    }

    p(r[n]);
    sum += v[n];
    cout << sum << " ";
    p(l[n]);
}

int main() {
    int a;
    cin >> a;
    v.resize(a + 1);
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
        while(true){
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
    p(1);
}