#include <iostream>
#include <vector>
using namespace std;

vector<int> ms(int n, vector<int> a){
    if (a.size() <= 1){
        return a;
    }

    vector<int> res(n);
    int i = 0, j = n - 1;
    int pos = n - 1;
    while (i <= j){
        if ((a[i] * a[i]) > (a[j] * a[j])){
            res[pos] = a[i] * a[i];
            i++;
        } else {
            res[pos] = a[j] * a[j];
            j--;
        }
        pos--;
    }
    return res;
}

int main() {
    int a;
    cin >> a;
    vector<int> v(a);
    for (int i = 0; i < a; i++){
        cin >> v[i];
    }

    v = ms(a, v);

    for (int i = 0; i < a; i++){
        cout << v[i] << " ";
    }
}