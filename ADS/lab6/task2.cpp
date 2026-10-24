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
    int a, b;
    cin >> a >> b;
    vector<int> v1(a);
    vector<int> v2(b);
    for (int i = 0; i < a; i++){
        cin >> v1[i];
    }
    for (int i = 0; i < b; i++){
        cin >> v2[i];
    }

    v1 = ms(v1);
    v2 = ms(v2);

    int i = 0, j = 0;
    bool f = true;
    while (i < a && j < b){
        if (v1[i] == v2[j]){
            if(!f){
                cout << " ";
            }
            cout << v1[i];
            f = false;
            i++;
            j++;
        } else if (v1[i] < v2[j]){
            i++;
        } else {
            j++;
        }
    }
}