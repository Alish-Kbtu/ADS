#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;

struct student{
    string last;
    string first;
    double gpa;
};

bool cmp(student a, student b){
    if(abs(a.gpa - b.gpa) > 1e-9){
        return a.gpa < b.gpa;
    }
    if (a.last != b.last){
        return a.last < b.last;
    }
    return a.first < b.first;
}

vector<student> ms(vector<student> a){
    if (a.size() <= 1){
        return a;
    }

    int mid = a.size() / 2;
    vector<student> l = ms(vector<student>(a.begin(), a.begin() + mid));
    vector<student> r = ms(vector<student>(a.begin() + mid, a.end()));

    vector<student> res;
    int i = 0, j = 0;
    while (i < l.size() && j < r.size()){
        if (cmp(l[i], r[j])){
            res.push_back(l[i++]);
        } else {
            res.push_back(r[j++]);
        }
    }
    while (i < l.size()){
        res.push_back(l[i++]);
    }
    while (j < r.size()){
        res.push_back(r[j++]);
    }
    return res;
}

double grade(string g){
    if (g == "A+") return 4.0;
    if (g == "A") return 3.75;
    if (g == "B+") return 3.5;
    if (g == "B") return 3.0;
    if (g == "C+") return 2.5;
    if (g == "C") return 2.0;
    if (g == "D+") return 1.5;
    if (g == "D") return 1.0;
    return 0.0;
}

int main(){
    int a;
    cin >> a;
    vector<student> v(a);
    for (int i = 0; i < a; i++){
        int x;
        cin >> v[i].last >> v[i].first >> x;

        double sum = 0;
        int credits = 0;
        for (int j = 0; j < x; j++){
            string g;
            int c;
            cin >> g >> c;
            sum += grade(g) * c;
            credits += c;
        }
        v[i].gpa = sum / credits;
    }

    v = ms(v);

    for (int i = 0; i < a; i++){
        printf("%s %s %.3f\n", v[i].last.c_str(), v[i].first.c_str(), v[i].gpa);
    }
}