/*
ID: sah2020
PROG: gift1
LANG: C++14
*/
#include <iostream>
#include <map>
//#include <string>
#include <fstream>

using namespace std;

int main() {
    ifstream cin ("gift1.in");
    ofstream cout ("gift1.out");
    int n;
    cin >> n;
    string names[20];
    map<string, int> moneys;
    for (int i = 0; i < n; ++i)
    {
        cin >> names[i];
        moneys[names[i]] = 0;
    }
    for (int i = 0; i < n; ++i)
    {
        string name;
        int sz, qn;
        cin >> name >> sz >> qn;
        if (qn == 0)
            continue;
        moneys[name] = moneys[name] - ((sz / qn) * qn);
        for (int j = 0; j < qn; ++j)
        {
            string name2;
            cin >> name2;
            moneys[name2] = moneys[name2] + sz / qn;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cout << names[i] << " " << moneys[names[i]] << '\n';
    }
}
