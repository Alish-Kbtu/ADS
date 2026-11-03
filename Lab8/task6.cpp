#include <iostream>
#include <vector>
#include <string>
using namespace std;

int countKMP(const string &p, const string &t) {
    int m = p.size();
    vector<int> pi(m, 0);
    for (int i = 1; i < m; i++) {
        int j = pi[i - 1];
        while (j > 0 && p[i] != p[j]) j = pi[j - 1];
        if (p[i] == p[j]) j++;
        pi[i] = j;
    }

    int cnt = 0, j = 0;
    for (int i = 0; i < (int)t.size(); i++) {
        while (j > 0 && t[i] != p[j]) j = pi[j - 1];
        if (t[i] == p[j]) j++;
        if (j == m) {
            cnt++;
            j = pi[j - 1];
        }
    }
    return cnt;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<string> p(n);
        for (int i = 0; i < n; i++) cin >> p[i];
        string t;
        cin >> t;

        vector<int> freq(n);
        int best = 0;
        for (int k = 0; k < n; k++) {
            freq[k] = countKMP(p[k], t);
            if (freq[k] > best) best = freq[k];
        }

        cout << best << "\n";
        for (int k = 0; k < n; k++) {
            if (freq[k] == best) cout << p[k] << "\n";
        }
    }
}