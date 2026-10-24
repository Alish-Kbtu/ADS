#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    vector<vector<int>> v(a, vector<int> (b));
    unordered_map<int, vector<vector<int>>> m;

    for (int i = 0; i < a; i++){
        int sum = 0;
        for (int j = 0; j < b; j++){
            cin >> v[i][j];
            sum += v[i][j];
        }
        m[sum].push_back(v[i]);
    }

    vector<int> sums;
    for (auto p : m){
        sums.push_back(p.first);
    }
    sort(sums.rbegin(), sums.rend());

    for (int s : sums){
        sort(m[s].begin(), m[s].end());
        for (auto r : m[s]){
            for (auto x : r){
                cout << x << " ";
            }
            cout << "\n";
        }
    }
}