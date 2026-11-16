#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int m = s.size();

    vector<int> p(m, 0);
    for (int i = 1; i < m; i++){
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j]){
            j = p[j - 1];
        }
        if (s[i] == s[j]){
            j++;
        }
        p[i] = j;

    }

    cout << m - p[m - 1];
}