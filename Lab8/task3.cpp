#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int a;
    cin >> a;
    vector<long long> v(a);
    for (int i = 0; i < a; i++){
        cin >> v[i];
    }

    string ans = "";
    long long prev = 0;
    for (int i = 0; i < a; i++){
        long long d = v[i] - prev;
        long long n = d / pow(2, i);
        ans += 'a' + n;
        prev = v[i];
    }
    cout << ans;
}