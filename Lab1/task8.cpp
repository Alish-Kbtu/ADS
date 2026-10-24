#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a;
    cin >> a;
    vector<int> s(a);
    for (int i = 0; i < a; i++){
        cin >> s[i];
    }
    vector<int> stk;
    vector<int> ans(a);

    for (int i = 0; i < a; i++){
        while(!stk.empty() && stk.back() >= s[i]){
            stk.pop_back();
        }

        if (stk.empty()) {
            ans[i] = -1;
        }
        else {
            ans[i] = stk.back();
        }

        stk.push_back(s[i]);
    }

    for (int i = 0; i < a; i++){
        cout << ans[i] << " ";
    }
}