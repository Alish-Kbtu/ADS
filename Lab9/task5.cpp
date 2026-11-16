#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int a;
    cin >> a;

    while (a--){
        string s;
        long long k;
        cin >> s >> k;
        int n = s.size();

        vector<int> p(n, 0);
        for (int i = 1; i < n; i++){
            int j = p[i - 1];
            while (j > 0 && s[i] != s[j]){
                j = p[j - 1];
            }
            if (s[i] == s[j]){
                j++;
            }
            p[i] = j;
        }

        long long ans = n + (k - 1) * (n - p[n - 1]);
        cout << ans << "\n";
    }
}