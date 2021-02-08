//http://codeforces.com/contest/727/problem/A

#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

long long a;
long long b;
long long path = -1;

const long long max = LLONG_MAX; 

void dfs(long long x, long long way) {
    if(x == b) {
        cout << "YES" << endl;
        path = way;
    } else if (x > b) {
        return;
    } else {
        dfs(x*2, way);
        dfs(x*10+1, way+1);
        if(way == path) {
            cout << x*2 << " ";
        } else if (way+1 == path) {
            cout << x*10 + 1 << " ";
        }
    }
}

int main() {

    cin>> a >> b; 
    dfs(a, 1);
}