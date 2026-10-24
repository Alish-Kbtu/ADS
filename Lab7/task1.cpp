#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<string> ms(vector<string> a){
    if (a.size() <= 1){
        return a;
    }

    int mid = a.size() / 2;
    vector<string> l = ms(vector<string>(a.begin(), a.begin() + mid));
    vector<string> r = ms(vector<string>(a.begin() + mid, a.end()));

    int i = 0, j = 0;
    vector<string> res;
    while (i < l.size() && j < r.size()){
        if (l[i].size() <= r[j].size()){        
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
    cin.ignore();

    for (int i = 0; i < a; i++){
        string s;
        getline(cin, s);

        vector<string> v;
        stringstream ss(s);
        string w;
        while (ss >> w){
            v.push_back(w);
        }

        v = ms(v);

        for (int j = 0; j < v.size(); j++){
            cout << v[j] << " ";
        }
        cout << '\n';
    }
}