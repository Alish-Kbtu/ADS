#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const long long B = 31;
const long long M1 = 1000000007;
const long long M2 = 998244353;

int main(){
    string s;
    getline(cin, s);
    int n = s.size();

    vector<long long> H1(n + 1, 0), H2(n + 1, 0), P1(n + 1, 1), P2(n + 1, 1);
    for (int i = 0; i < n; i++){
        long long c = s[i] - 'a' + 1;
        H1[i + 1] = (H1[i] * B + c) % M1;
        H2[i + 1] = (H2[i] * B + c) % M2;
        P1[i + 1] = P1[i] * B % M1;
        P2[i + 1] = P2[i] * B % M2;
    }

    long long ans = 0;
    for (int len = 1; len <= n; len++){
        vector<pair<long long, long long>> v;
        for (int i = 0; i + len <= n; i++){
            long long a = (H1[i + len] - H1[i] * P1[len] % M1 + M1) % M1;
            long long b = (H2[i + len] - H2[i] * P2[len] % M2 + M2) % M2;
            v.push_back({a, b});
        }
        sort(v.begin(), v.end());
        ans += unique(v.begin(), v.end()) - v.begin();
    }
    cout << ans;
}