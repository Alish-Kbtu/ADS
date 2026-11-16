#include <iostream>
#include <vector>
#include <string>
using namespace std;

int same[2001][2001];

int main() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--){
        for (int j = n - 1; j >= 0; j--){
            if (s[i] == s[j]){
                same[i][j] = same[i + 1][j + 1] + 1;
            }
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        int c = 0;
        for (int j = 0; j < n; j++){
            if (same[l - 1][j] >= len){
                c++;
            }
        }
        cout << c << "\n";
    }
}