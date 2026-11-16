#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int main() {
    string s;
    int a;
    cin >> s >> a;
    for (char &c : s){
        c = tolower(c);
    }
    vector<string> towns(a);
    for (int i = 0; i < a; i++){
        cin >> towns[i];
    }

    vector<int> len(a);
    for (int i = 0; i < a; i++){
        string low = towns[i];
        low[0] = tolower(low[0]);

        string w = low + "#" + s;
        vector<int> p(w.size(), 0);

        for (int k = 1; k < (int)w.size(); k++){
            int j = p[k - 1];
            while (j > 0 && w[k] != w[j]){
                j = p[j - 1];
            }
            if (w[k] == w[j]){
                j++;
            }
            p[k] = j;
        }
        len[i] = p.back();  
    }

    int m = 0;
    for (int i = 0; i < a; i++){
        if (len[i] > m){
            m = len[i];
        }
    }

    if (m == 0){
        cout << 0;
        return 0;
    }

    int c = 0;
    for (int i = 0; i < a; i++){
        if (len[i] == m){
            c++;
        }
    }

    cout << c << "\n";
    for (int i = 0; i < a; i++){
        if (len[i] == m){
            cout << towns[i] << "\n";
        }
    }
}