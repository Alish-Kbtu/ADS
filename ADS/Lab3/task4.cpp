#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int a, b;
    cin >> a;
    vector<int> v(a);
    for (int i = 0; i < a; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    vector<long long> s(a + 1);
    s[0] = 0;
    for (int i = 0; i < a; i++){
        s[i + 1] = s[i] + v[i];
    }

    cin >> b;
    for (int i = 0; i < b; i++){
        int p;
        cin >> p;

        int l = 0, r = a;
        while(l < r){
            int mid = (l + r) / 2;
            if (v[mid] > p){
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << l << " " <<s[l]<< "\n";
    }
}