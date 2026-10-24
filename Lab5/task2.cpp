#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int a;
    cin >> a;
    priority_queue<int> pq;
    for (int i = 0; i < a; i++){
        int x;
        cin >> x;
        pq.push(x);
    }

    while(pq.size() > 1){
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        if (x != y){
            pq.push(x - y);
        }
    }
    if (pq.empty()){
        cout << 0;
    } else {
        pq.top();
    }
}