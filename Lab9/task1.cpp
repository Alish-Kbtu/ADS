#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int as = a.size();
    int bs = b.size();
    int k = (bs + as - 1) / as;
    string s = "";
    for (int i = 0; i < k + 1; i++){
        s += a;
    }

    int p = s.find(b);
    if (p == string::npos){
        cout << -1;
    } else {
        cout << (p + as + bs - 1) / as;
    }
}