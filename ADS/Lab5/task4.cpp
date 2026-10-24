#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < a; i++){
        int x;
        cin >> x;
        pq.push(x);
    }

    int c = 0;
    while( pq.top() < b){
        if (pq.size() == 1){
            cout << -1;
            return 0;
        }

        long long n = pq.top();
        pq.pop();
        long long m = pq.top();
        pq.pop();
        pq.push(n + 2 * m);
        c++;
    }
    cout << c;
}