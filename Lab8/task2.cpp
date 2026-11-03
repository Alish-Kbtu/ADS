#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> z(string s){
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++){
        if (i < r) z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] > r){
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main(){
    string s1, s2, t;
    cin >> s1 >> s2 >> t;
    int n1 = s1.size(), n2 = s2.size(), m = t.size();

    vector<int> z1 = z(t + "#" + s1);
    vector<int> z2 = z(t + "#" + s2);

    int ans = 0;
    for (int i = 0; i + m <= min(n1, n2); i++){
        if (z1[m + 1 + i] >= m && z2[m + 1 + i] >= m) ans++;
    }
    cout << ans << "\n";
}