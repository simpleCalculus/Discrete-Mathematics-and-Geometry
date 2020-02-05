# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <cmath>

using namespace std;

const int hight = 180;
const int weight = 75;

bool comp(pair<pair <int, int>, string> s, pair<pair <int, int>, string> p) {
    if(abs(s.first.first - hight) == abs(p.first.first - hight)) {
        if(abs(s.first.second - weight) == abs(p.first.second - weight)) {
            if(s.first.second == p.first.second) {
                return s.second < p.second;
            } else {
                return s.first.second < p.first.second;
            }
        } else if(abs(s.first.second - weight) < abs(p.first.second - weight)) {
            if(s.first.second <= weight) {
                return true;
            }
            else if(p.first.second <= weight) {
                return false;
            }
            else {
                return s.first.second < p.first.second;
            }
        } else {
            if(p.first.second <= weight) {
                return false;
            }
            else if(s.first.second <= weight) {
                return true;
            }
            else {
                return s.first.second < p.first.second;
            }
        }
    } else {
        return abs(s.first.first - hight) < abs(p.first.first - hight);
    }
}

int main() {
    int n;
    vector <pair<pair <int, int>, string>> v;
    cin >> n;
    for(int u = 0; u < n; ++u) {
        string s;
        int a, b;
        cin >> s >> a >> b;
        v.push_back(make_pair(make_pair(a, b), s));
    }
    sort(v.begin(), v.end(), comp);
    for(int i = 0; i < n; i++) {
        cout << v[i].second;
//        cout << "  " << v[i].first.first << "  " << v[i].first.second;
        cout << "\n";
    }
}
