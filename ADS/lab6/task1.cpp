#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isv(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool cmp(char x, char y){
    if (isv(x) != isv(y)){
        return isv(x);
    }
    return x < y;
}

vector<char> ms(vector<char> a){
    if (a.size() <= 1){
        return a;
    }

    int mid = a.size() / 2;
    vector<char> l = ms(vector<char>(a.begin(), a.begin() + mid));
    vector<char> r = ms(vector<char>(a.begin() + mid, a.end()));

    vector<char> res;
    int i = 0, j = 0;
    while (i < l.size() && j < r.size()){
        if (cmp(l[i], r[j])){
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
    string s;
    cin >> s;

    vector<char> v(s.begin(), s.end());
    v = ms(v);

    string ans(v.begin(), v.end());
    cout << ans;
}