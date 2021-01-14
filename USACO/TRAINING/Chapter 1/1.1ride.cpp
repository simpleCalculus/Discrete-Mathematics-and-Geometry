/*
ID: sah2020
PROG: ride
LANG: C++14
*/

# include <iostream>
# include <fstream>
# include <string>
using namespace std;

int Calc(string name)
{
    int ans = 1;
    for (int i = 0; i < name.size(); ++i)
        ans = (ans * (name[i] - 'A' + 1)) % 47;
    return ans;
}

int main()
{
    ofstream cout ("ride.out");
    ifstream cin ("ride.in");
    string line1, line2;
    cin >> line1 >> line2;
    if (Calc(line1) == Calc(line2))
        cout << "GO\n";
    else
        cout << "STAY\n";
}
