//http://codeforces.com/contest/727/problem/A

#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

long long a;
long long b;
bool found = false;

const long long max = LLONG_MAX; 
vector<long long> answ;

void dfs(long long x, long long way) {
    if(x == b) {
        cout << "YES"<< endl;
        found = true;
        answ.push_back(x);
    } else if (x > b || found) {
        return;
    } else {
        dfs(x*2, way);
        dfs(x*10+1, way+1);
        if(found) answ.push_back(x);
    }
}

int main() {

    cin>> a >> b; 
    dfs(a, 1);

    if(found) {
        cout << answ.size() << endl;
        for (int i = answ.size()-1; i >= 0; i--)
        {
            cout << answ[i] << " ";
        }
    } else {
        cout << "NO";
    }
    
    
}