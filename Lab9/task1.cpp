#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();

    string t = "";
    int k = m / n + 2;
    for (int i = 0; i < k; i++) t += a;

    string s = b + "#" + t;
    vector<int> pi(s.size(), 0);

    for (int i = 1; i < s.size(); i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;

        if (pi[i] == m) {
            int end = i - m;
            cout << (end + n - 1) / n;
            return 0;
        }
    }

    cout << -1;
    return 0;
}