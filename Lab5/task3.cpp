#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    priority_queue<int> pq;
    for (int i = 0; i < a; i++){
        int x;
        cin >> x;
        pq.push(x);
    }

    long long ans = 0;
    for (int i = 0; i < b; i++){
        ans += pq.top();
        int s = pq.top() - 1;
        pq.pop();
        pq.push(s);
    }
    cout << ans;
}