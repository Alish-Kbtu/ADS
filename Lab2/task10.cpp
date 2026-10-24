#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    int a;

    while(cin >> a && a != 0){
        if (a == 1){
            int x, p;
            cin >> x >> p;
            v.insert(v.begin() + p, x);
        } else if (a == 2){
            int p;
            cin >> p;
            v.erase(v.begin() + p);
        } else if (a == 3){
            if (v.empty()){
                cout << -1;
            } else{
                for (int i = 0; i < v.size(); i++){
                    cout << v[i] << " ";
                }
            }
            cout << "\n";
        } else if (a == 4){
            int p1, p2;
            cin >> p1 >> p2;
            int x = v[p1];
            v.erase(v.begin() + p1);
            v.insert(v.begin() + p2, x);
        } else if (a == 5){
            reverse(v.begin(), v.end());
        } else if (a == 6){
            int x;
            cin >> x;
            rotate(v.begin(), v.begin() + x, v.end());
        } else if (a == 7){
            int x;
            cin >> x;
            rotate(v.begin(), v.end() - x, v.end());
        }
    }
}