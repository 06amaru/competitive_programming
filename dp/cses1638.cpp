#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
char S[1000][1000];
ll G[1000][1000];

const ll MOD = 1e9+7;

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) 
    {
		for (int j = 0; j < n; j++)
        {
            cin >> S[i][j];
            G[i][j] = 0;
        }
        
	}

    for(int i = 0; i < n; i++) {
        if(S[0][i] != '*') G[0][i] = 1;
        else break;
    }
    for(int i = 0; i < n; i++) {
        if(S[i][0] != '*') G[i][0] = 1;
        else break;
    }

    for(int i = 1; i < n; i++) 
    {
        for (int j = 1; j < n; j++)
        {
            if(S[i][j] != '*') {
                G[i][j] = (G[i-1][j]+G[i][j-1])% MOD;
            }
        }
    }

    cout << G[n-1][n-1];
}
