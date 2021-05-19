#include <bits/stdc++.h>

using namespace std;

const int N = 2*1e5+2;

vector<pair<int,int>> v;

int main() {
    int n, x, e;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> e;
        v.push_back({e, i+1});
    }

    sort(v.begin(), v.end());

    int i = 0;
    int j = n-1;

    while(i < j) {
        while(v[i].first + v[j].first > x) {
            j--;
        }
        if(v[i].first + v[j].first == x) break;
        i++;
    }
    if(i < j) {
        cout << v[j].second << ' ' << v[i].second;
    } else cout << "IMPOSSIBLE";
}