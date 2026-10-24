#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> s(n + 1);
    s[0] = 0;
    for (int i = 1; i <= n; i++){
        long long a;
        cin >> a;
        s[i] = s[i - 1] + a;
    }

    int ans = n;
    for (int l = 1; l <= n; l++){
        int r = lower_bound(s.begin() + l, s.end(), s[l - 1] + k) - s.begin();
        if (r <= n){
            ans = min(ans, r - l + 1);
        }
    }
    cout << ans << '\n';
}