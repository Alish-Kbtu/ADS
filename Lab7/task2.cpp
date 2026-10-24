#include <iostream>
#include <vector>
using namespace std;

vector<int> ms(vector<int> a, vector<int> b){
    vector<int> l = a;
    vector<int> r = b;

    int i = 0, j = 0;
    vector<int> res;
    while (i < l.size() && j < r.size()){
        if (l[i] <= r[j]){
            res.push_back(l[i++]);
        } else {
            res.push_back(r[j++]);
        }
    }
    while (i < l.size()){
        res.push_back(l[i++]);
    }
    while (j < r.size()){
        res.push_back(r[j++]);
    }
    return res;
}

int main() {
    int a;
    cin >> a;
    vector<int> v1(a);
    for (int i = 0; i < a; i++){
        cin >> v1[i];
    }

    int b;
    cin >> b;
    vector<int> v2(b);
    for (int i = 0; i < b; i++){
        cin >> v2[i];
    }
    vector<int> ans;
    ans = ms(v1, v2);

    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}