#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int a;
    cin >> a;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < a; i++){
        int x;
        cin >> x;
        pq.push(x);
    }

    int ans = 0;
    while(pq.size() > 1){
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        pq.push(a + b);
        ans += a + b;
    }

    cout << ans;
}