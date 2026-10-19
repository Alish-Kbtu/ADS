#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    while (a--) {
        int n;
        cin >> n;
        char s[500];
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        for (int i = 0; i < n; i++) {
            int cnt[26] = {0};
            for (int j = 0; j <= i; j++) {
                cnt[s[j] - 'a']++;
            }

            int ans = -1;
            for (int j = 0; j <= i; j++) {
                if (cnt[s[j] - 'a'] == 1) {
                    ans = s[j];
                    break;
                }
            }

            if (ans == -1){
                cout << -1;
            }
            else{
                cout << (char)ans;
            } 
            if (i + 1 < n) cout << " ";
        }
        cout << "\n";
    }
}