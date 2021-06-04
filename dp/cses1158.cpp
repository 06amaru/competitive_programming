#include <bits/stdc++.h>

using namespace std;

typedef int ll;

const int X = 1e5+2;
const int N = 1002;


ll price[N]={0};
ll page[N]={0};
ll dp[N][X]={0};

int main() {
    ll n,x;
    //x max budget to buy
    cin >> n >> x;

    for(int i = 1; i <= n; i++) {
        cin >> price[i];
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> page[i];
    }
    for (int i = 0; i < x; ++i) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n ; ++i) {
        for (int j = 1; j <= x; ++j) {
            dp[i][j] = 0;
            if(j-price[i] >= 0) {
                ll buy = dp[i-1][j - price[i]] + page[i];
                ll not_buy =dp[i-1][j];
                dp[i][j] = max(buy, not_buy);
            } else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][x];
    return 0;

}
