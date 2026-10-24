#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

vector<int> ms(vector<int> a){
    if (a.size() <= 1){
        return a;
    }

    int mid = a.size() / 2;
    vector<int> l = ms(vector<int>(a.begin(), a.begin() + mid));
    vector<int> r = ms(vector<int>(a.begin() + mid, a.end()));

    vector<int> res;
    int i = 0, j = 0;
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

int main(){
    int a;
    cin >> a;
    vector<int> v(a);
    int d, m, y;
    char c;
    for (int i = 0; i < a; i++){
        cin >> d >> c >> m >> c >> y;
        int x = y * 10000 + m * 100 + d;
        v[i] = x;
    }
    v = ms(v);

    for (int i = 0; i < a; i++){
        int y, m, d;
        y = v[i] / 10000;
        m = v[i] / 100 % 100;
        d = v[i] % 100;
        printf("%02d-%02d-%04d\n", d, m, y);
    }
}