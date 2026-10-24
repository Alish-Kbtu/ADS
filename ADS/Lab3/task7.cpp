#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    vector<double> v(a);
    double m = 0;
    for (int i = 0; i < a; i++){
        cin >> v[i];
        if (v[i] > m) m = v[i];
    }

    double l = 0, r = m;
    for (int i = 0; i < 100; i++){
        double mid = (l + r) / 2;

        long long c = 0;
        for (int j = 0; j < a; j++){
            c += (long long)(v[j] / mid);
            if (c >= b){
                break;
            }
        }

        if (c >= b){
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << fixed << setprecision(9) << l;
}