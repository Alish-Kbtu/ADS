#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

const long long mod = 1000000007LL;

string h(const string& s){
    long long h = 0, p = 1;
    for (char c : s){
        h = (h + (c - 47) * p) % mod;
        p = p * 11 % mod;
    }

    return to_string(h);
}

int main() {
    int a;
    cin >> a;
    vector<string> v(a * 2);
    unordered_map<string, int> mp;
    for (int i = 0; i < a * 2; i++){
        cin >> v[i];
        mp[v[i]]++;
    }

    int c = 0;
    for (int i = 0; i < a * 2 && c < a; i++){
        string x = h(v[i]);
        if (mp.count(x)){
            cout << "Hash of string \"" << v[i] << "\" is " << x << '\n';
            c++;
        }
    }
}