#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int main() {
    int q, k;
    cin >> q >> k;
    priority_queue<int, vector<int>, greater<int>> pq;
    long long sum = 0;

    for (int i = 0; i < q; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "insert") {
            int n;
            cin >> n;
            pq.push(n);
            sum += n;
            if ((int)pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
        } else {
            cout << sum << "\n";
        }
    }
    return 0;
}