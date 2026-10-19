#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int a;
    cin >> a;
    string cur;
    vector<string> uni;
    cin >> cur;
    uni.push_back(cur);
    
    for (int i = 0; i < a - 1; i++){
        cin >> cur;
        if (uni.back() != cur){
            uni.push_back(cur);
        }
    }

    cout << uni.size();
    for (int i = 0; i < uni.size(); i++){
        cout << uni[i] << " ";
    }
}