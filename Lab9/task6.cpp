#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    cin >> s2 >> s1;
    int m = s1.size();

    string w = s1 + "#" + s2;
    vector<int> p(w.size(), 0);
    
    vector<int> ans;
    for (int i = 1; i < w.size(); i++){
        int j = p[i - 1];
        while (j > 0 && w[i] != w[j]){
            j = p[j - 1];
        }
        if (w[i] == w[j]){
            j++;
        }
        p[i] = j;

        if (m == p[i]){
            ans.push_back(i - 2 * m + 1);
        }
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}