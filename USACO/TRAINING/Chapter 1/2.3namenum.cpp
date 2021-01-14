/*
ID: sah2020
PROG: namenum
LANG: C++14
*/
//# include <iostream>
# include <vector>
# include <algorithm>
# include <fstream>
# include <string>
# include <map>
using namespace std;

vector<string> names;
map<char, int> mp;

void GetNames()
{

    string line;
    ifstream in("dict.txt");
    if (in.is_open())
    {
        while (getline(in, line))
        {
            names.push_back(line);
        }
    }
    in.close();
}

void FillMap()
{
    int rule = 0;
    int ind = 2;
    for (char i = 'A'; i <= 'Y'; ++i)
    {
        if (i == 'Q')
        {
            continue;
        }
        mp[i] = ind;
        rule++;
        if (rule % 3 == 0)
            ind++;
    }
}

void Solve(string number)
{
    ofstream cout ("namenum.out");
    string ans = "NONE\n";
    for (size_t i = 0; i < names.size(); ++i)
    {
        if (names[i].size() != number.size())
            continue;
        bool check = true;
        for (int j = 0; j < number.size(); ++j)
        {
            if (mp[names[i][j]] != number[j] - '0')
            {
                check = false;
                break;
            }
        }
        if (check)
        {
            ans = "";
            cout << names[i] << "\n";
        }
    }
    cout << ans;
}

int main()
{
    GetNames();
    FillMap();
    ifstream cin ("namenum.in");
    string number;
    cin >> number;
    Solve(number);
}
