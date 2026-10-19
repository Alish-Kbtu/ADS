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
        if (l[i] >= r[j]){
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
    vector<vector<int>> m(a, vector<int>(b));
    
    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            cin >> m[i][j];
        }
    }

    for (int i = 0; i < b; i++){
        vector<int> c(a);
        for (int j = 0; j < a; j++){
            c[j] = m[j][i];
        }
        c = ms(c);
        for (int j = 0; j < a; j++){
            m[j][i] = c[j];
        }
    }

    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
}