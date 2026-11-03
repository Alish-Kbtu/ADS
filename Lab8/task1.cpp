#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

long long mod = 1000000007;

long long h(string s){
    long long res = 0;
    long long p = 1;
    for (char c : s){
        res = (res + (c - 47) * p) % mod;
        p = p * 11 % mod;
    }
    return res;
}

int main() {
    int a;
    cin >> a;
    vector<string> v(2 * a);
    unordered_set<string> s;
    for (int i = 0; i < a * 2; i++){
        cin >> v[i];
        s.insert(v[i]);
    }

    long long c = 0;
    for (int i = 0; i < a * 2; i++){
        string x = to_string(h(v[i]));
        if (s.count(x)){
            cout << "Hash of string \"" << v[i] << "\" is " << x << "\n";
        }
    }
}