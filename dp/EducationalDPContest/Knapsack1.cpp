// https://atcoder.jp/contests/dp/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int X = 1e5+2;
const int N = 102;


ll weight[N]={0};
ll value[N]={0};
ll dp[N][X]={0};

int main() {
    ll n, w;
    //w capacity knapsack
    cin >> n >> w;

    for(int i = 1; i <= n; i++) {
        cin >> weight[i];
        cin >> value[i];
    }

    for (int i = 1; i <= n ; ++i) {
        for (int j = 1; j <= w; ++j) {
            if(j-weight[i] >= 0) {
                ll take = dp[i-1][j - weight[i]] + value[i];
                ll not_take =dp[i-1][j];
                dp[i][j] = max(take, not_take);
            } else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][w];
    return 0;

}
