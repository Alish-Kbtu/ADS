#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string t, a;
    cin >> t >> a;
    if (t.size() != a.size()){
        cout << -1;
        return 0;
    }
    int n = a.size();

    string w = t + "#" + a + a;
    vector<int> p(w.size(), 0);
    int c = 0;

    for (int i = 1; i < w.size(); i++){
        int j = p[i - 1];
        while (j > 0 && w[i] != w[j]){
            j = p[j - 1];
        }
        if (w[i] == w[j]){
            j++;
        }
        p[i] = j;

        if (j == n){
            cout << i - 2 * n;
            return 0;
        }
    }

    cout << -1;
    return 0;
}