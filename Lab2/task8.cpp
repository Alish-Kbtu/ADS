#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a;
    cin >> a;
    vector<int> v(a);
    for (int i = 0; i < a; i++){
        cin >> v[i];
    }

    int ans = v[0];
    for (int i = 0; i < a; i++){
        int sum = 0;
        for (int j = i; j < a; j++){
            sum += v[j];
            if (sum > ans){
                ans = sum;
            }
        }
    }
    cout << ans;
}