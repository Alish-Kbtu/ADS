#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    int a;
    cin >> a;

    while(a--){
        int s;
        cin >> s;
        deque<int> d;
        for (int i = 1; i <= s; i++){
            d.push_back(i);
        }

        vector<int> r(s+1);

        for (int i = 1; i <= s; i++){
            int size = d.size();
            int m = i % size;

            for (int j = 0; j < m; j++){
                int front = d.front();
                d.pop_front();
                d.push_back(front);
            }
            int p = d.front();
            d.pop_front();
            r[p] = i;
        }
        for (int i = 1; i <= s; i++){
            cout << r[i] << " ";
        }
        cout << "\n";
    }
}