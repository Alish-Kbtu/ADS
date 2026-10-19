#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int cnt[26] = {0};
    for (char c : s){
        cnt[c - 'a']++;
    }

    string res;
    res.reserve(s.size());
    for(int i = 0; i < 26; i++){
        res += string(cnt[i], 'a' + i);
    }
    cout << res;
}