#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> ans;
    int a;
    cin >> a;
    vector<int> f(a);
    for (int i = 0; i < a; i++){
        cin >> f[i];
        ans.push_back(f[i]);
    }

    int b;
    cin >> b;
    vector<int> s(b);
    for (int i = 0; i < b; i++){
        cin >> s[i];
        ans.push_back(s[i]);
    }

    sort(ans.begin(), ans.end());
    for(int i = 0; i < a + b; i++){
        cout << ans[i] << " ";
    }
}