#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> z(string s){
    int n = s.size();
    vector<int> v(n, 0);
    int l = 0, r = 0;
    for (int i = 0; i < n; i++){
        if (i < r){
            v[i] = min(r - i, v[i - l]);
        }
        while (i + v[i] < n && s[v[i]] == s[v[i] + i]){
            v[i]++;
        }
        if (v[i] + i > r){
            l = i;
            r = v[i] + i;
        }
    }
    return v;
}

int main() {
    string s1, s2, t;
    cin >> s1 >> s2 >> t;
    int n1 = s1.size();
    int n2 = s2.size();
    int m = t.size();

    vector<int> z1 = z(t + "#" + s1);
    vector<int> z2 = z(t + "#" + s2);

    int ans = 0;
    for (int i = 0; i + m < min(n1, n2); i++){
        if (z1[m + 1 + i] == z2[m + i + 1]){
            ans++;
        }
    }
    cout << ans;
}