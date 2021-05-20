#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v;
    stack<int> s;

    int n, e;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> e;
        v.push_back(e);
    }

    int extracted = 0;
    int index = -1;
    for (int i = 0; i < n; ++i) {
        while(v[i] <= extracted && s.size() > 0) {
            index = s.top();
            extracted = v[index];
            if( extracted < v[i]) break;
            s.pop();
        }
        if(v[i] <= extracted) cout << 0 << ' ';
        else cout << index+1 << ' ';

        s.push(i);
        index = s.top();
        extracted = v[index];
    }

}