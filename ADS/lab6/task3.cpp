#include <iostream>
#include <vector>
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
        } else{
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
    vector<int> v(a);
    for (int i = 0; i < a; i++){
        cin >> v[i];
    }
    v = ms(v);
    long long b = 999999999;
    for (int i = 1; i < a; i++){
        int x = v[i] - v[i - 1];
        if (x < b){
            b = x;
        }
    }

    for (int i = 1; i < a; i++){
        if ((v[i] - v[i - 1]) == b){
            cout << v[i - 1] << " " << v[i];
        }
    }
}