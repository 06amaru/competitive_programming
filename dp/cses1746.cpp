#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9+7;

ll x[100002]={0};

ll dp[100002][102];

int main() {
    ll n;
    ll m;

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    for(int i = 1; i <= n; i++) {
        if(x[i] != 0) {
            int c = x[i];
            if(i == 1) { dp[1][c] = 1; continue;}
            dp[i][c] = dp[i-1][c];
            if(c>1) dp[i][c] += dp[i-1][c-1];
            if(c<m) dp[i][c] += dp[i-1][c+1];
            dp[i][c] = dp[i][c] % MOD;
        } else {
            for(int c = 1; c <= m; c++) {
                if(i==1) {dp[1][c] = 1; continue;}
                dp[i][c] = dp[i-1][c];
                if(c > 1) dp[i][c] += dp[i-1][c-1];
                if(c < m) dp[i][c] += dp[i-1][c+1];
                dp[i][c] = dp[i][c] % MOD;
            }
        }
    }
    if(x[n] != 0) cout << dp[n][x[n]] << endl;
    else {
        ll ans = 0;
        for (int c = 1; c <= m; c++) {
            ans += dp[n][c];
            ans = ans % MOD;
        }
        cout << ans << endl;
    }

    return 0;

}
