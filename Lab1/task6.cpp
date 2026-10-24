#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    string r1, r2;

    for ( int i = 0; i < s1.size(); i++){
        if( s1[i] == '#'){
            if( !r1.empty()){
                r1.pop_back();
            }
        }
        else {
            r1 += s1[i];
        }
    }

    for ( int i = 0; i < s2.size(); i++){
        if( s2[i] == '#'){
            if( !r2.empty()){
                r2.pop_back();
            }
        }
        else{
            r2 += s2[i];
        }
    }

    if (r1 == r2){
        cout << "Yes";
    }
    else {
        cout << "No";
    }
}