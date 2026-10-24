#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    vector<long long> val(a + 1);
    vector<int> l(a + 1, 0);
    vector<int> r(a + 1, 0);

    int c = 0;
    for (int i = 0; i < a; i++){
        int x;
        cin >> x;

        if (c == 0){
            c = 1;
            val[1] = x;
            continue;
        }

        int cur = 1;
        int depth = 0;
        while(depth < 100){
            if (x <= val[cur]){
                if (l[cur] == 0){
                    c++;
                    val[c] = x;
                    l[cur] = c;
                    break;
                }
                cur = l[cur];
            } else {
                if (r[cur] == 0){
                    c++;
                    val[c] = x;
                    r[cur] = c;
                    break;
                }
                cur = r[cur];
            }
            depth++;
        }
    }
    for (int i = 0; i < b; i++){
        string s;
        cin >> s;

        int cur = 1;
        bool b = true;
        for (int j = 0; j < s.size(); j++){
            if (s[j] == 'L'){
                cur = l[cur];
            } else {
                cur = r[cur];
            }
            if (cur == 0){
                b = false;
                break;
            }
        }
        if (b){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}