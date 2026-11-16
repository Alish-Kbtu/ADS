#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s, t;
    int k;
    cin >> s >> k >> t;
    int m = s.size();

    string w = s + "#" + t;
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

        if (j == m){
            c++;
        }
    }

    if (c >= k){
        cout << "YES";
    } else {
        cout << "NO";
    }
}