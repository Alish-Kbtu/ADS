#include <iostream>
#include <vector>
using namespace std;

long long c = 0;

vector<int> ms(vector<int> a){
    if (a.size() <= 1){
        return a;
    }

    int mid = a.size() / 2;
    vector<int> l = ms(vector<int>(a.begin(), a.begin() + mid));
    vector<int> r = ms(vector<int>(a.begin() + mid, a.end()));

    int i = 0, j = 0;
    vector<int> res;
    while (i < l.size() && j < r.size()){
        if (l[i] <= r[j]){
            res.push_back(l[i++]);
        } else {
            res.push_back(r[j++]);
            c += l.size() - i;
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
    cout << c;
}