#include <bits/stdc++.h>

using namespace std;

int dp[3002][3002];

char bt[3002][3002];
//diagonal D
//left L
//up U
int main() {

    string s, t;
    cin >> s  >> t;
    for(int i = 1; i <= s.size(); i++) {
        for(int j = 1; j <= t.size(); j++) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                bt[i][j] = 'D';
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                bt[i][j] = dp[i-1][j] < dp[i][j-1] ? 'L' : 'U';
            }
        }
    }

    int i = s.size();
    int j = t.size();
    string answ = "";
    while(i != 0 && j != 0) {
        if(bt[i][j] == 'D') {
            if(s[i-1] == t[j-1]) {
                answ.push_back(s[i-1]);
            }
            i--;
            j--;
        } else if (bt[i][j] == 'L') {
            j--;
        } else if (bt[i][j] == 'U') {
            i--;
        }
    }

    for (int k = answ.size()-1; k >= 0 ; --k) {
        cout << answ[k];
    }
    cout << endl;
}
