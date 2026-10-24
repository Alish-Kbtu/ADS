#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int a;
    cin >> a;
    map<string, string> m;
    for (int i = 0; i < a; i++){
        string oldn, newn;
        cin >> oldn >> newn;

        if (m.count(oldn)){
            string s = m[oldn];
            m.erase(oldn);
            m[newn] = s;
        } else {
            m[newn] = oldn;
        }
    }

    map<string, string> ans;
    for (auto s : m){
        ans[s.second] = s.first;
    }

    cout << ans.size() << "\n";
    for (auto s : ans){
        cout << s.first << " " << s.second << "\n";

    }
}